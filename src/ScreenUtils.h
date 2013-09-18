#pragma once

#include <PolyPhysicsScreen.h>
#include <PolyScreenEntityInstance.h>
#include <vector>
#include <map>

class ScreenUtils
{
	public:
		static void setupScreenFromEntity2dFileWithMapCfg( 
			Polycode::PhysicsScreen* targetScene, 
			Polycode::String entity2d, 
			Polycode::String mapCfg );
	
	private:
		static std::vector<Polycode::Entity*> extractLayersFromEntity2dFile( Polycode::ScreenEntityInstance* entity2d );
		static std::map<std::string, Polycode::ScreenEntity*> extractScreenEntitiesFromLayer( Polycode::Entity* layer );
};