#pragma once

#include <PolyString.h>
#include <PolyResourceManager.h>
#include <PolyCoreServices.h>
#include <map>
#include <yaml-cpp/yaml.h>
#include "GlobalDef.h"

/*
 *	Polycode::ResourceManager wrapper
 * 
 *	@author: quepas
 */
class ResourceMgr
{
	public:
						
		Polycode::String getFilepath(Polycode::String id);		
		Polycode::ResourceManager* getPolyResourceMgr() { return polyResourceMgr; }

		Polycode::Texture* getTexture(Polycode::String name);		
		void loadFromDirectoryFile(Polycode::String file);

		static ResourceMgr& getInstance()
		{
			static ResourceMgr instance;
			return instance;
		}

		static const std::string GFX_TEXTURE;
		static const std::string GFX_SPRITE;
		static const std::string GFX_SHADER;
		static const std::string SFX_SOUND;
		static const std::string SFX_MUSIC;
		static const std::string I18N;
		static const std::string CFG_SPELL;

	private:
		ResourceMgr();
		ResourceMgr(const ResourceMgr&) {}
		ResourceMgr& operator=(const ResourceMgr&) {}

		void parseDirectoryFile(Polycode::String file);				
		void loadFromNonEmptyDirectory(std::string dir);
			
		std::map<std::string, Polycode::String> directories;
		Polycode::ResourceManager* polyResourceMgr;
};