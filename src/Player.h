#pragma once

#include <PolyScreenImage.h>
#include <PolyPhysicsScreen.h>
#include <PolyString.h>

/*
 *	@author: quepas
 */
class Player : public Polycode::ScreenImage
{	
	public:
		enum MOTION
		{
			LEFT = 0,
			RIGHT = 1,
			UP = 2,
			DOWN = 3,
			JUMP = 4,
			JUMP_RAISE = 5,
			JUMP_FALL = 6			 
		};
		
		Player(Polycode::PhysicsScreen* screen, int x, int y, 
			const Polycode::String& fileName);
				
		void beginMove(MOTION direction);
		void endMove(MOTION direction);
		void Jump();

		void Update();

		static const Number MOVEMENT_SPEED;
		static const Number JUMP_MAX_SPEED;
		static const Number JUMP_SPEED_DIVIDER;
	private:
		bool activeMoves[7];
		Polycode::Vector2 motionVector; // TODO: for vector-based movement
		Polycode::Vector2 jumpVector;
		Polycode::PhysicsScreen* screen;

		Polycode::Vector2 calculateMovement();
		Polycode::Vector2 calculateJump();
};