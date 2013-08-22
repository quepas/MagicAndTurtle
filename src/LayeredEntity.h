#pragma once

#include <PolyScreenEntity.h>
#include <vector>

class LayeredEntity : public Polycode::ScreenEntity
{
	public:		
		LayeredEntity(int _maxLayer = 10);
		~LayeredEntity();

		void Add(Polycode::ScreenEntity* entity, unsigned int numLayer = 1);
		void changeLayerTo(Polycode::ScreenEntity* entity, unsigned int numLayer);
		unsigned int getMaxLayers();
		Polycode::ScreenEntity* getLayer(unsigned int numLayer);

	private:
		struct EntityLinkData
		{
			EntityLinkData()
				:	layer(1), entity(nullptr) {}
			EntityLinkData(Polycode::ScreenEntity* _entity, int _layer)
				:	layer(_layer), entity(_entity) {}

			int layer;
			Polycode::ScreenEntity* entity;
		};

		std::vector<Polycode::ScreenEntity*> layers;
		std::vector<EntityLinkData*> entities;
		const int maxLayer;	

		EntityLinkData* getEntityLinkData(Polycode::ScreenEntity* entity);
		int checkAndReturnLayerValue(int numLayer);
		bool checkOffset(int offset, int currentLayer);

		void createLayers(int layersNumber);

};