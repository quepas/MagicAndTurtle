#pragma once

#include <vector>
#include <map>

#include <PolyVector2.h>

class TileDataSet
{
	public:
		struct tileData
		{
			bool isStatic;
			bool hasAnimiation;
			std::vector<std::string> animiationNames;
		};

		static Polycode::Vector2 tileSize;
		static std::map<char, std::string> tilesMap;
		static std::map<char, tileData*> tilesData;

		static TileDataSet& getInstance() 
		{
			static TileDataSet instance;
			return instance;
		}
	private:
		TileDataSet();
		TileDataSet(const TileDataSet&) {}
		TileDataSet& operator=(const TileDataSet&) {}
		
		static void initTilesMap();
		static void initTilesData();
};