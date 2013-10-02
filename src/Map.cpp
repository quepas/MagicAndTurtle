#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>

#include "GlobalDef.h"

#include <PolyScreenImage.h>
#include <PolyPhysicsScreenEntity.h>

using namespace Polycode;

Map::Map( std::string filename )	
	: size(0, 0)
{	
	openFromFile(filename);
}

void Map::openFromFile( std::string filename )
{
	std::ifstream file(filename.c_str());
	std::string line;

	if(file.is_open())
	{
		while(getline(file, line))
		{
			// debug
			std::cout << line << std::endl;			
			addLineAndUpdateSize(line);
		}
	}
	else 
	{
		std::cout << "Couldn't load file: " << filename << std::endl;
	}
	// debug
	std::cout << "Map size x: " << size.x << "; y: " << size.y << std::endl;
}

void Map::addLineAndUpdateSize( std::string line )
{
	content.push_back(line);
	++size.x;

	if(line.length() > size.y)
	{
		size.y = line.length();
	}
}

void Map::renderOnScreen( Polycode::PhysicsScreen* screen )
{
	if(size.x > 0 && size.y > 0)
	{
		for(uint16 i = 0; i < size.y; ++i)
		{
			for(uint16 j = 0; j < size.x; ++j)
			{
				if(TileDataSet::getInstance().tilesMap.find(content[j].at(i)) 
					!= TileDataSet::getInstance().tilesMap.end())
				{
					std::string dir = TileDataSet::getInstance().tilesMap[content[j].at(i)];
					// debug purpose
					std::cout << "tile x: " << i << "; y: " << j << std::endl;
					ScreenImage* image = new ScreenImage(dir);
					image->setPosition(i * TileDataSet::getInstance().tileSize.x,
									   j * TileDataSet::getInstance().tileSize.y);
					screen->addPhysicsChild(image, PhysicsScreenEntity::ENTITY_RECT, true);
				}				
			}
		}
	}
}

