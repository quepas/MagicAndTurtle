#include "ResourceMgr.h"

using namespace Polycode;

const std::string ResourceMgr::GFX_TEXTURE = "gfx_texture";
const std::string ResourceMgr::GFX_SPRITE = "gfx_sprite";
const std::string ResourceMgr::GFX_SHADER = "gfx_shader";
const std::string ResourceMgr::SFX_SOUND = "sfx_sound";
const std::string ResourceMgr::SFX_MUSIC = "sfx_music";
const std::string ResourceMgr::I18N = "i18n";
const std::string ResourceMgr::CFG_SPELL = "cfg_spell";

ResourceMgr::ResourceMgr( String file /*= ""*/ )
{
	directories = std::map<std::string, String>();
	polyResourceMgr = CoreServices::getInstance()->getResourceManager();
	polyResourceMgr -> addArchive("res/default.pak");
	polyResourceMgr -> addDirResource("default", false);

	if(file.length() > 0)
		loadFromDirectoryFile(file);
}

ResourceMgr::~ResourceMgr()
{

}

String ResourceMgr::getFilepath( String id )
{
	String file = directories[id.getSTLString()];
	if(file.length() > 0)
		return file;
	return String(NONE);
}

void ResourceMgr::parseDirectoryFile( String file )
{
	static std::string keyType = "type";
	static std::string keyDir = "dir";
	static std::string keyFile = "file";			
	YAML::Node nodes = YAML::LoadFile(file.contents);

	for(auto it = nodes.begin(); it != nodes.end(); ++it)
	{				
		std::string type = (*it)[keyType].as<std::string>();
		String reference;

		if((*it)[keyDir].IsDefined()) {
			reference = (*it)[keyDir].as<std::string>();
		} else if((*it)[keyFile].IsDefined()) {
			reference = (*it)[keyFile].as<std::string>();
		}

		if(type.length() > 0 && reference.length() > 0)			
			directories.insert(std::make_pair(type, reference));
	}
}

void ResourceMgr::loadFromDirectoryFile( String file )
{
	parseDirectoryFile(file);

	loadFromNonEmptyDirectory(GFX_TEXTURE);
	loadFromNonEmptyDirectory(GFX_SPRITE);
	loadFromNonEmptyDirectory(GFX_SHADER);
	loadFromNonEmptyDirectory(SFX_MUSIC);
	loadFromNonEmptyDirectory(SFX_SOUND);
	loadFromNonEmptyDirectory(I18N);
	loadFromNonEmptyDirectory(CFG_SPELL);	
}

void ResourceMgr::loadFromNonEmptyDirectory( std::string dir )
{
	if(directories.find(dir) != directories.end())
		polyResourceMgr->addDirResource(directories[dir]);
}
