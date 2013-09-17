#pragma once

#include <vector>
#include <PolyScreenEntity.h>
#include "LayeredEntity.h"

class ParallaxBackground : public LayeredEntity
{
	public:
		ParallaxBackground(unsigned int numLayer);
		~ParallaxBackground();

		void Scroll(Number x, Number y);
	private:
		static const float LAYER_BASE_SPEED; /* = 1 */
		static const float LAYER_INTERVAL_SPEED; /* = 0.25f */

		Number calculateLayerSpeed(int layer_number);
};