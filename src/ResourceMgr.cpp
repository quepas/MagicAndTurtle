#include "ResourceMgr.h"

ResourceMgr::ResourceMgr( Polycode::String file /*= ""*/ )
{
	directories = std::map<std::string, Polycode::String>();
	polyResourceMgr = 
		Polycode::CoreServices::getInstance()->getResourceManager();
	polyResourceMgr -> addArchive("res/default.pak");
	polyResourceMgr -> addDirResource("default", false);

	if(file.length() > 0)
		loadFromDirectoryFile(file);
}

ResourceMgr::~ResourceMgr()
{

}

Polycode::String ResourceMgr::getFilepath( Polycode::String id )
{
	Polycode::String file = directories[id.getSTLString()];
	if(file.length() > 0)
		return file;
	return Polycode::String(NONE);
}

void ResourceMgr::parseDirectoryFile( Polycode::String file )
{
	static std::string keyType = "type";
	static std::string keyDir = "dir";
	static std::string keyFile = "file";			
	YAML::Node nodes = YAML::LoadFile(file.contents);

	for(auto it = nodes.begin(); it != nodes.end(); ++it)
	{				
		std::string type = (*it)[keyType].as<std::string>();
		Polycode::String reference;

		if((*it)[keyDir].IsDefined()) {
			reference = (*it)[keyDir].as<std::string>();
		} else if((*it)[keyFile].IsDefined()) {
			reference = (*it)[keyFile].as<std::string>();
		}

		if(type.length() > 0 && reference.length() > 0)			
			directories.insert(std::make_pair(type, reference));
	}
}

void ResourceMgr::loadFromDirectories()
{
	static std::string typeGfxTexture = "gfx_texture";
	static std::string typeGfxSprite = "gfx_sprite";
	static std::string typeGfxShader = "gfx_shader";
	static std::string typeSfxSound = "sfx_sound";
	static std::string typeSfxMusic = "sfx_music";
	static std::string typei18n = "i18n";
	static std::string typeCfgSpell = "cfg_spell";
}

void ResourceMgr::loadFromDirectoryFile( Polycode::String file )
{
	parseDirectoryFile(file);
	loadFromDirectories();
}
