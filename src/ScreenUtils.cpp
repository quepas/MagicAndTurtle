#include "ScreenUtils.h"

#include <PolyPhysicsScreenEntity.h>
#include <iostream>

using namespace Polycode;
using namespace std;

vector<Entity*> ScreenUtils::extractLayersFromEntity2dFile( ScreenEntityInstance* entity2d )
{
	vector<Entity*> result;
	uint16 layersNumber = entity2d -> getNumChildren();

	for(uint16 i = 0; i < layersNumber; ++i) 
	{
		result.push_back(entity2d -> getChildAtIndex(i));
	}
	return result;
}

map<string, ScreenEntity*> ScreenUtils::extractScreenEntitiesFromLayer( Entity* layer )
{
	map<string, ScreenEntity*> result;
	uint16 entitiesNumber = layer -> getNumChildren();

	for(uint16 i = 0; i < entitiesNumber; ++i) 
	{
		ScreenEntity* entity = (ScreenEntity*)layer->getChildAtIndex(i);
		string id = entity -> id.getSTLString();

		result.insert(make_pair(id, entity));
	}
	return result;
}

void ScreenUtils::setupScreenFromEntity2dFileWithMapCfg( 
						Polycode::PhysicsScreen* targetScene, 
						Polycode::String entity2d_file, 
						Polycode::String mapCfg_file )
{
	ScreenEntityInstance* screenEntity2d = new ScreenEntityInstance(entity2d_file);
	screenEntity2d->Translate(-100, 100, 0); // for now

	if(screenEntity2d)
	{
		targetScene->addChild(screenEntity2d);
		vector<Entity*> layers = extractLayersFromEntity2dFile(screenEntity2d);

		for(uint16 i = 0; i < layers.size(); ++i)
		{
			map<string, ScreenEntity*> entitesFromLayer = extractScreenEntitiesFromLayer(layers[i]);
			
			for(auto it = entitesFromLayer.begin(); it != entitesFromLayer.end(); ++it)
			{
				cout << "Entity: " << it -> first << endl;
				targetScene->trackPhysicsChild(it -> second, PhysicsScreenEntity::ENTITY_RECT, false);
			}
		}
	}	
}


