#pragma once

#include <vector>
#include <PolyScreenEntity.h>

class ParallaxBackground : public Polycode::ScreenEntity
{
	public:
		ParallaxBackground();
		~ParallaxBackground();

		void Add(Polycode::ScreenEntity* entity, int layer_number = 1);
		void Scroll(Number x, Number y);
		void changeLayerTo(Polycode::ScreenEntity* entity, int new_layer_number);

		//void remove(Polycode::ScreenEntity* entity);
	private:
		static const float LAYER_BASE_SPEED; /* = 1 */
		static const float LAYER_INTERVAL_SPEED; /* = 0.25f */
		static const int LAYER_MAX_NUMBER = 10;

		struct LayerEntity;

		int calculateLayerSpeed(int layer_number);
		int findEntityIndex(Polycode::ScreenEntity* entity);
		LayerEntity* getLayerEntity(Polycode::ScreenEntity* entity);
		void applyLayerOffset(LayerEntity* layeredEntity, int offset);
		void scrollEntityBasedOnLayer(LayerEntity* layeredEntity);
		std::vector<LayerEntity*> entities;
};