#pragma once

#include <PolyScreenImage.h>
#include <PolyScreenSprite.h>
#include <PolyPhysicsScreen.h>
#include <PolyString.h>

/*
 *	@author: quepas
 */
class Player : public Polycode::ScreenSprite
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
			JUMP_FALL = 6,
			NONE = 7
		};
		
		Player(Polycode::PhysicsScreen* screen, int x, int y, 
			const Polycode::String& fileName);
				
		void beginMove(MOTION direction);
		void endMove(MOTION direction);
		void Jump();
		void Teleport(Polycode::Vector2 pos);

		void Update();

		static const Number MOVEMENT_SPEED;
		static const Number JUMP_MAX_SPEED;
		static const Number JUMP_SPEED_DIVIDER;

		static const Polycode::String MOVE_LEFT_ANIM;
		static const Polycode::String IDLE_LEFT_ANIM;
		static const Polycode::String JUMP_LEFT_ANIM;
		static const Polycode::String MOVE_RIGHT_ANIM;
		static const Polycode::String IDLE_RIGHT_ANIM;
		static const Polycode::String JUMP_RIGHT_ANIM;
	private:
		bool activeMoves[7];
		MOTION lastMove;
		Polycode::Vector2 motionVector; // TODO: for vector-based movement
		Polycode::Vector2 jumpVector;
		Polycode::PhysicsScreen* screen;

		Polycode::Vector2 calculateMovement();
		Polycode::Vector2 calculateJump();		
};