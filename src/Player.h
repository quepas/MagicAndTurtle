#pragma once

#include <PolyScreenImage.h>
#include <PolyString.h>

/*
 *	@author: quepas
 */
class Player : public Polycode::ScreenImage
{	
	public:
		enum DIRECTION
		{
			LEFT = 0,
			RIGHT = 1,
			UP = 2,
			DOWN = 3
		};

		Player(int x, int y, const Polycode::String& fileName);
		
		void beginMove(DIRECTION direction);
		void endMove(DIRECTION direction);

		void Update();

		static const int MOVEMENT_SPEED = 10;
	private:
		bool activeMoves[4];

		Polycode::Vector3 calculateMovement();
};