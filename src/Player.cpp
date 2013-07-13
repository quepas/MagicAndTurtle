#include "Player.h"

using namespace Polycode;

Player::Player(int x, int y, const String& fileName) : ScreenImage(fileName)
{
	setPosition(x, y);

	activeMoves[LEFT] = false;
	activeMoves[RIGHT] = false;
	activeMoves[UP] = false;
	activeMoves[DOWN] = false;
}

void Player::beginMove(DIRECTION direction)
{
	activeMoves[direction] = true;
}

void Player::endMove(DIRECTION direction)
{
	activeMoves[direction] = false;
}

void Player::Update()
{
	ScreenImage::Update();
	Translate(calculateMovement());
}

Vector3 Player::calculateMovement()
{
	int leftRightShift = 0;
	int upDownShift = 0;

	if(activeMoves[LEFT]) {
		leftRightShift -= MOVEMENT_SPEED;
	}
	if(activeMoves[RIGHT]) {
		leftRightShift += MOVEMENT_SPEED;
	}
	if(activeMoves[UP]) {
		upDownShift -= MOVEMENT_SPEED;
	}
	if(activeMoves[DOWN]) {
		upDownShift += MOVEMENT_SPEED;
	}
	return Vector3(leftRightShift, upDownShift, 0);
}
