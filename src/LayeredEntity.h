#pragma once

#include <PolyScreenEntity.h>
#include <vector>

class LayeredEntity : public Polycode::ScreenEntity
{
	public:		
		LayeredEntity(int _maxLayer = 10);
		~LayeredEntity();

		void Add(Polycode::ScreenEntity* entity, int numLayer = 1);
		void changeLayerTo(Polycode::ScreenEntity* entity, int numLayer);
	private:
		struct LayeredData
		{
			LayeredData()
				:	layer(1), entity(nullptr) {}
			LayeredData(Polycode::ScreenEntity* _entity, int _layer)
				:	layer(_layer), entity(_entity) {}

			int layer;
			Polycode::ScreenEntity* entity;
		};

		std::vector<LayeredData*> entities;
		const int maxLayer;	

		LayeredData* getEntityLayeredData(Polycode::ScreenEntity* entity);
		int checkAndReturnLayerValue(int numLayer);
		bool checkOffset(int offset, int currentLayer);

};