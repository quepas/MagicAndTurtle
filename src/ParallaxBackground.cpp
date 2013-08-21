#include "ParallaxBackground.h"
#include <cmath>

using namespace Polycode;

const float ParallaxBackground::LAYER_BASE_SPEED = 1.0f;
const float ParallaxBackground::LAYER_INTERVAL_SPEED = 0.25f;

ParallaxBackground::ParallaxBackground()
{}


ParallaxBackground::~ParallaxBackground()
{}

struct ParallaxBackground::LayerEntity
{	
	int layer_number;
	ScreenEntity* entity;

	LayerEntity() {}
	LayerEntity(ScreenEntity* _entity, int _layer_number)
		: entity(_entity), layer_number(_layer_number)
	{}
};

void ParallaxBackground::Add(ScreenEntity* entity, int layer_number /* = 1 */)
{
	LayerEntity* insertedEntity = new LayerEntity(entity, layer_number);
	entities.push_back(insertedEntity);
	applyLayerOffset(insertedEntity, layer_number - 1);
}

void ParallaxBackground::changeLayerTo(Polycode::ScreenEntity* entity, int new_layer_number)
{
	LayerEntity* changedEntity = getLayerEntity(entity);

	if(changedEntity != nullptr)
	{
		int offset = new_layer_number - (changedEntity -> layer_number);
		applyLayerOffset(changedEntity, offset);
	}
}

int ParallaxBackground::calculateLayerSpeed(int layer_number)
{
	return LAYER_BASE_SPEED + (layer_number - 1) * LAYER_INTERVAL_SPEED;
}

int ParallaxBackground::findEntityIndex(Polycode::ScreenEntity* entity)
{
	for(int i = 0; i < entities.size(); ++i)
	{
		if(entities[i] -> entity == entity) 
		{
			return i;
		}
	}	
	return -1;
}

ParallaxBackground::LayerEntity* ParallaxBackground::getLayerEntity(Polycode::ScreenEntity* entity)
{
	int index = findEntityIndex(entity);	
	
	if(index >= 0 && index < entities.size())
	{
		return entities[index];
	}
	return nullptr;
}

void ParallaxBackground::applyLayerOffset(LayerEntity* layeredEntity, int offset)
{
	// move up
	if(offset > 0)
	{
		for(int i = 0; i < offset; ++i)
		{
			moveChildUp(layeredEntity -> entity);
			++(layeredEntity -> layer_number);
		}
	}
	// move down
	else if(offset < 0)
	{		
		for(int i = 0; i < abs(offset); ++i)
		{
			moveChildDown(layeredEntity -> entity);
			--(layeredEntity -> layer_number);
		}
		// if we gone to far
		if(layeredEntity -> layer_number < 1)
		{
			layeredEntity -> layer_number = 1;
		}
	}
}

void ParallaxBackground::Scroll( Number x, Number y )
{
	for (int i = 0; i < entities.size(); ++i)
	{
		scrollEntityBasedOnLayer(entities[i]);
	}
}

void ParallaxBackground::scrollEntityBasedOnLayer( LayerEntity* layeredEntity )
{

}

