#include "Player.h"
#include "SpellFactory.h"
#include "MoveTo.h"

using namespace Polycode;

const Number Player::MOVEMENT_SPEED = Number(15);
const Number Player::JUMP_MAX_SPEED = Number(40);
const Number Player::JUMP_SPEED_DIVIDER = Number(80.0);

const String Player::MOVE_LEFT_ANIM = "l_move";
const String Player::IDLE_LEFT_ANIM = "l_idle";
const String Player::JUMP_LEFT_ANIM = "l_jump";
const String Player::MOVE_RIGHT_ANIM = "r_move";
const String Player::IDLE_RIGHT_ANIM = "r_idle";
const String Player::JUMP_RIGHT_ANIM = "r_jump";

Player::Player(Polycode::PhysicsScreen* _screen, int x, int y, 
	const Polycode::String& fileName)
	: ScreenSprite(fileName, 88, 147), screen(_screen)
{
	setPosition(x, y);

	activeMoves[LEFT] = false;
	activeMoves[RIGHT] = false;
	activeMoves[UP] = false;
	activeMoves[DOWN] = false;
	activeMoves[JUMP] = false;
	activeMoves[JUMP_RAISE] = false;
	activeMoves[JUMP_FALL] = false;
	lastMove = NONE;

	motionVector = Vector2(0, 0);
	jumpVector = Vector2(0, 0);	

	this -> addAnimation(IDLE_RIGHT_ANIM, "0", 1);
	this -> addAnimation(IDLE_LEFT_ANIM, "7", 1);
	this -> addAnimation(MOVE_RIGHT_ANIM, "0, 1, 2", 0.5);	
	this -> addAnimation(MOVE_LEFT_ANIM, "7, 6, 5", 0.5);
	this -> addAnimation(JUMP_RIGHT_ANIM, "3", 1);
	this -> addAnimation(JUMP_LEFT_ANIM, "4", 1);
	this -> playAnimation(IDLE_RIGHT_ANIM, 0, false);
}

void Player::beginMove(MOTION direction)
{
	activeMoves[direction] = true;
		
	if(activeMoves[LEFT])
	{
		lastMove = LEFT;
		if(!activeMoves[JUMP])
		this -> playAnimation(MOVE_LEFT_ANIM, 0, false);
	} 
	else if(activeMoves[RIGHT]) 
	{
		lastMove = RIGHT;
		if(!activeMoves[JUMP])
		this -> playAnimation(MOVE_RIGHT_ANIM, 0, false);
	}				
}

void Player::endMove(MOTION direction)
{
	if(activeMoves[LEFT] || activeMoves[RIGHT]) {
		screen -> setVelocityX(this, 0);
	}	
	activeMoves[direction] = false;
	if(!activeMoves[JUMP])
	{
		if(lastMove == LEFT)
		{
			this -> playAnimation(IDLE_LEFT_ANIM, 0, false);
		} 
		else if(lastMove == RIGHT)
		{
			this -> playAnimation(IDLE_RIGHT_ANIM, 0, false);
		}
	}		
}

void Player::Jump()
{		
	activeMoves[JUMP] = true;	
	activeMoves[JUMP_RAISE] = true;

	jumpVector = Vector2(0, -JUMP_MAX_SPEED);
	if(lastMove == LEFT)
	{
		this ->playAnimation(JUMP_LEFT_ANIM, 0, false);
	}
	else if(lastMove == RIGHT)
	{
		this ->playAnimation(JUMP_RIGHT_ANIM, 0, false);
	}	
}

void Player::Update()
{
	ScreenSprite::Update();
	Vector2 movement = calculateMovement();
	screen -> setVelocity(this, movement.x, movement.y);	

	// player moves
	Event* event = new Event(Event::EVENTBASE_NONPOLYCODE+113);	
	this -> dispatchEvent(event, Event::EVENTBASE_NONPOLYCODE+113);
}

Vector2 Player::calculateMovement()
{	
	Vector2 movement = Vector2(0, 0);	

	if(activeMoves[LEFT]) {
		movement.x -= MOVEMENT_SPEED;		
	}
	if(activeMoves[RIGHT]) {
		movement.x += MOVEMENT_SPEED;		
	}
	if(activeMoves[UP]) {
		//movement.y -= MOVEMENT_SPEED;
	}
	if(activeMoves[DOWN]) {
		//movement.y += MOVEMENT_SPEED;
	}
	if(activeMoves[JUMP]) {
		movement += calculateJump();					
	}	
	return movement;
}

Vector2 Player::calculateJump()
{
	Vector2 jump = Vector2(0, 0);

	if(activeMoves[JUMP])
	{
		if(lastMove == LEFT)
		{
			this ->playAnimation(JUMP_LEFT_ANIM, 0, false);
		}
		else if(lastMove == RIGHT)
		{
			this ->playAnimation(JUMP_RIGHT_ANIM, 0, false);
		}	
	}

	if(activeMoves[JUMP_RAISE]) 
	{
		jump = Vector2(jumpVector.x, jumpVector.y);
		jumpVector += Vector2(0, JUMP_MAX_SPEED / JUMP_SPEED_DIVIDER);

		if(jumpVector.y >= 0) {
			jumpVector = Vector2(0, 0);
			activeMoves[JUMP_RAISE] = false;
			activeMoves[JUMP_FALL] = true;
			activeMoves[JUMP] = false; // TODO: hack
			if(lastMove == LEFT)
			{				
				this ->playAnimation(IDLE_LEFT_ANIM, 0, false);
			}
			else if(lastMove == RIGHT)
			{
				this ->playAnimation(IDLE_RIGHT_ANIM, 0, false);
			}	
		}
	}
	return jump;
}

void Player::Teleport(Vector2 pos){
	setPosition(pos);
}

void Player::Cast( Spell::TYPE type )
{
	Spell* castedSpell = SpellFactory::getInstance().createSpell(type);
	Vector2 position = getPosition2D();
	Vector2 destination = Vector2(position.x, position.y);

	destination.x += (lastMove == LEFT) ? -1 : 1;

	castedSpell -> setPosition(position);
	screen -> addChild(castedSpell);
	new MoveTo(castedSpell, 2000, 100.0f, destination);
}
