#include "Player.h"

using namespace Polycode;

const Number Player::MOVEMENT_SPEED = Number(1.2);
const Number Player::JUMP_MAX_SPEED = Number(2.0);
const Number Player::JUMP_SPEED_DIVIDER = Number(80.0);

Player::Player(int x, int y, const String& fileName) : ScreenImage(fileName)
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
	Translate(calculateMovement());
}

Vector3 Player::calculateMovement()
{
	Vector3 movement = Vector3(0);	

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

Vector3 Player::calculateJump()
{
	Vector3 jump = Vector3(0);

	if(activeMoves[JUMP_RAISE]) 
	{
		jump = Vector3(jumpVector.x, jumpVector.y, 0);
		jumpVector += Vector2(0, JUMP_MAX_SPEED / JUMP_SPEED_DIVIDER);

		if(jumpVector.y >= 0) {
			jumpVector = Vector2(0, 0);
			activeMoves[JUMP_RAISE] = false;
			activeMoves[JUMP_FALL] = true;
		}
	} 
	else if(activeMoves[JUMP_FALL]) 
	{		
		jump = Vector3(jumpVector.x, jumpVector.y, 0);
		jumpVector += Vector2(0, JUMP_MAX_SPEED / JUMP_SPEED_DIVIDER);

		// TODO: check for collision!
		if(jumpVector.y >= JUMP_MAX_SPEED) {
			jumpVector = Vector2(0, JUMP_MAX_SPEED);
			activeMoves[JUMP] = false;
			activeMoves[JUMP_RAISE] = false;
			activeMoves[JUMP_FALL] = false;
		}
	}

	return jump;
}
