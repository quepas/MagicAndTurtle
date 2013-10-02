#include "TileDataSet.h"

using namespace Polycode;

std::map<char, TileDataSet::tileData*> TileDataSet::tilesData = std::map<char, TileDataSet::tileData*>();
std::map<char, std::string> TileDataSet::tilesMap = std::map<char, std::string>();
Vector2 TileDataSet::tileSize = Vector2(70, 70);

TileDataSet::TileDataSet()
{
	initTilesMap();
	initTilesData();
}

void TileDataSet::initTilesMap()
{
	tilesMap['x'] = "res/gfx/external/Tiles/box.png";
	tilesMap['o'] = "res/gfx/external/Tiles/boxCoin.png";

}

void TileDataSet::initTilesData()
{
	
}
