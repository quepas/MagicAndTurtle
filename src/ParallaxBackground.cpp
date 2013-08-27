#include "ParallaxBackground.h"
#include <cmath>
#include <iostream>

using namespace Polycode;

const float ParallaxBackground::LAYER_BASE_SPEED = 1.0f;
const float ParallaxBackground::LAYER_INTERVAL_SPEED = 0.25f;

ParallaxBackground::ParallaxBackground(unsigned int numLayer)
	: LayeredEntity(numLayer)
{}

ParallaxBackground::~ParallaxBackground()
{}

Number ParallaxBackground::calculateLayerSpeed(int layer_number)
{
	return LAYER_BASE_SPEED + (getMaxLayers() - layer_number) * LAYER_INTERVAL_SPEED;
}

void ParallaxBackground::Scroll( Number x, Number y )
{	
	// scroll each layer with different speed
	unsigned int layersNumber = getMaxLayers();

	for(unsigned int i = 1; i <= layersNumber; ++i)
	{		
		ScreenEntity* layer = getLayer(i);
		Number layerSpeed = calculateLayerSpeed(i);
		layer->Translate(-x*layerSpeed, -y*layerSpeed, 0);
	}
}