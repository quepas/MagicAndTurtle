#pragma once

#include <PolyString.h>
#include <map>
#include <yaml-cpp/yaml.h>
#include "GlobalDef.h"

class ResourcesData
{
	public:
		ResourcesData(Polycode::String file = "")
		{
			if(file.length() > 0)
				parseDirectoryFile(file);
		}
		~ResourcesData() {};

		Polycode::String getFilepath(Polycode::String id)
		{
			Polycode::String file = directories[id];
			if(file.length() > 0)
				return file;
			return Polycode::String(NONE);
		}

		void parseDirectoryFile(Polycode::String file)
		{
			YAML::Node nodes = YAML::LoadFile(file.contents);

			for(auto it = nodes.begin(); it != nodes.end(); ++it)
			{
				// TODO: if multiple same 'type' entry -> concat res dir
				Polycode::String type = (*it)["type"].as<std::string>();
				Polycode::String directory = (*it)["dir"].as<std::string>();

				if(type.length() > 0 && directory.length() > 0)			
					directories.insert(std::make_pair(type, directory));
			}
		}

	private:
		std::map<Polycode::String, Polycode::String> directories;
};