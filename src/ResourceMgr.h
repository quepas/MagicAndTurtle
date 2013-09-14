#pragma once

#include <PolyString.h>
#include <PolyResourceManager.h>
#include <PolyCoreServices.h>
#include <map>
#include <yaml-cpp/yaml.h>
#include "GlobalDef.h"

class ResourceMgr
{
	public:
		ResourceMgr(Polycode::String file = "");		
		~ResourceMgr();

		Polycode::String getFilepath(Polycode::String id);		
		Polycode::ResourceManager* getPolyResourceMgr() { return polyResourceMgr; }

		void loadFromDirectoryFile(Polycode::String file);		
	private:

		void parseDirectoryFile(Polycode::String file);		
		void loadFromDirectories() ;
			
		std::map<std::string, Polycode::String> directories;
		Polycode::ResourceManager* polyResourceMgr;
};