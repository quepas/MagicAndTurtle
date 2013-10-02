#pragma once

#include <PolyVector2.h>
#include <PolyPhysicsScreen.h>
#include <vector>
#include <map>

#include "TileDataSet.h"

class Map
{
	public:
		Map(std::string filename);
		~Map() {};
		
		Polycode::Vector2 getSize() { return size; }
		void renderOnScreen(Polycode::PhysicsScreen* screen);
	private:						
		std::vector<std::string> content;
		Polycode::Vector2 size;

		void openFromFile(std::string filename);
		void addLineAndUpdateSize(std::string line);
};