#include "Player.h"

using namespace Polycode;

const Number Player::MOVEMENT_SPEED = Number(10);
const Number Player::JUMP_MAX_SPEED = Number(40);
const Number Player::JUMP_SPEED_DIVIDER = Number(80.0);

Player::Player(Polycode::PhysicsScreen* _screen, int x, int y, 
	const Polycode::String& fileName)
	: ScreenImage(fileName), screen(_screen)
{
	setPosition(x, y);

	activeMoves[LEFT] = false;
	activeMoves[RIGHT] = false;
	activeMoves[UP] = false;
	activeMoves[DOWN] = false;
	activeMoves[JUMP] = false;
	activeMoves[JUMP_RAISE] = false;
	activeMoves[JUMP_FALL] = false;

	motionVector = Vector2(0, 0);
	jumpVector = Vector2(0, 0);
}

void Player::beginMove(MOTION direction)
{
	activeMoves[direction] = true;
}

void Player::endMove(MOTION direction)
{
	activeMoves[direction] = false;
}

void Player::Jump()
{
	activeMoves[JUMP] = true;	
	activeMoves[JUMP_RAISE] = true;

	jumpVector = Vector2(0, -JUMP_MAX_SPEED);
}

void Player::Update()
{
	ScreenImage::Update();
	Vector2 movement = calculateMovement();
	screen -> setVelocity(this, movement.x, movement.y);
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

	if(activeMoves[JUMP_RAISE]) 
	{
		jump = Vector2(jumpVector.x, jumpVector.y);
		jumpVector += Vector2(0, JUMP_MAX_SPEED / JUMP_SPEED_DIVIDER);

		if(jumpVector.y >= 0) {
			jumpVector = Vector2(0, 0);
			activeMoves[JUMP_RAISE] = false;
			activeMoves[JUMP_FALL] = true;
		}
	}

	return jump;
}
