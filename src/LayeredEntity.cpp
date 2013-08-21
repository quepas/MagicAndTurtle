#include "LayeredEntity.h"

#include <iostream>

using namespace Polycode;

LayeredEntity::LayeredEntity( int _maxLayer /*= 10*/ )
	: maxLayer(_maxLayer)
{
}

LayeredEntity::~LayeredEntity()
{
}

void LayeredEntity::Add( Polycode::ScreenEntity* entity, int numLayer /*= 1*/ )
{
	addChild(entity);
	numLayer = checkAndReturnLayerValue(numLayer);
	LayeredData* layeredData = new LayeredData(entity, 1);
	entities.push_back(layeredData);
	changeLayerTo(entity, numLayer);
}

void LayeredEntity::changeLayerTo( Polycode::ScreenEntity* entity, int numLayer )
{
	LayeredData* entityLayeredData = getEntityLayeredData(entity);
	if(entityLayeredData)
	{
		int offset = checkAndReturnLayerValue(numLayer) - (entityLayeredData -> layer);		
		if(checkOffset(offset, entityLayeredData -> layer))
		{
			for(int i = 0; i < abs(offset); ++i)
			{
				if(offset > 0) // move up
				{
					std::cout << "Move up" << std::endl;
					moveChildUp(entityLayeredData -> entity);
					++(entityLayeredData -> layer);
				} 
				else // move down
				{
					std::cout << "Move down" << std::endl;
					moveChildDown(entityLayeredData -> entity);
					--(entityLayeredData -> layer);
				}
			}
		}		
	}
}

LayeredEntity::LayeredData* LayeredEntity::getEntityLayeredData
	( Polycode::ScreenEntity* entity )
{
	if(entity) 
	{
		for(auto it = entities.begin(); it != entities.end(); ++it)
		{
			if((*it) -> entity == entity) 			
				return *it;			
		}
	}
	return nullptr;
}

int LayeredEntity::checkAndReturnLayerValue( int numLayer )
{
	if(numLayer < 1) 
		return 1;
	if(numLayer > maxLayer)
		return maxLayer;
	return numLayer;
}

bool LayeredEntity::checkOffset( int offset, int currentLayer )
{
	int newLayerNumber = currentLayer + offset;
	return newLayerNumber >= 1 && newLayerNumber <= maxLayer;	
}
