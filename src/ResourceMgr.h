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

		static const std::string GFX_TEXTURE;
		static const std::string GFX_SPRITE;
		static const std::string GFX_SHADER;
		static const std::string SFX_SOUND;
		static const std::string SFX_MUSIC;
		static const std::string I18N;
		static const std::string CFG_SPELL;
	private:

		void parseDirectoryFile(Polycode::String file);				
		void loadFromNonEmptyDirectory(std::string dir);
			
		std::map<std::string, Polycode::String> directories;
		Polycode::ResourceManager* polyResourceMgr;
};