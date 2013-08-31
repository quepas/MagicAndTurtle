#include "LayeredEntity.h"

#include <iostream>

using namespace Polycode;

LayeredEntity::LayeredEntity( int _maxLayer /*= 10*/ )
	: maxLayer(_maxLayer)
{
	createLayers(maxLayer);
}

LayeredEntity::~LayeredEntity()
{
}

void LayeredEntity::Add( Polycode::ScreenEntity* entity, unsigned int numLayer /*= 1*/ )
{	
	numLayer = checkAndReturnLayerValue(numLayer);
	layers[numLayer-1] -> addChild(entity);

	EntityLinkData* entityData = new EntityLinkData(entity, numLayer);
	entities.push_back(entityData);
}

void LayeredEntity::changeLayerTo( Polycode::ScreenEntity* entity, unsigned int numLayer )
{
	// TODO: rewrite it!
	EntityLinkData* entityLayeredData = getEntityLinkData(entity);
	if(entityLayeredData)
	{
		int offset = checkAndReturnLayerValue(numLayer) - (entityLayeredData -> layer);		
		if(checkOffset(offset, entityLayeredData -> layer))
		{
			for(unsigned int i = 0; i < abs(offset); ++i)
			{
				if(offset > 0) // move up
				{					
					moveChildUp(entityLayeredData -> entity);
					++(entityLayeredData -> layer);
				} 
				else // move down
				{					
					moveChildDown(entityLayeredData -> entity);
					--(entityLayeredData -> layer);
				}
			}
		}		
	}
}

LayeredEntity::EntityLinkData* LayeredEntity::getEntityLinkData
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

void LayeredEntity::createLayers( int layersNumber )
{
	for(int i = 0; i < layersNumber; ++i)
	{
		ScreenEntity* layer = new ScreenEntity();
		addChild(layer);
		moveChildBottom(layer);		
		layers.push_back(layer);
	}
}

unsigned int LayeredEntity::getMaxLayers()
{
	return maxLayer;
}

Polycode::ScreenEntity* LayeredEntity::getLayer(unsigned int numLayer)
{
	numLayer = checkAndReturnLayerValue(numLayer);
	return layers[numLayer-1];
}
