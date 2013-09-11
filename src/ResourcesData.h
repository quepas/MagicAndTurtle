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
				parseFile(file);
		}
		~ResourcesData() {};

		Polycode::String getFilepath(Polycode::String id)
		{
			Polycode::String file = data[id];
			if(file.length() > 0)
				return file;
			return Polycode::String(NONE);
		}

		void parseFile(Polycode::String file)
		{
			YAML::Node nodes = YAML::LoadFile(file.contents);

			for(auto it = nodes.begin(); it != nodes.end(); ++it)
			{
				Polycode::String id = (*it)["resourceId"].as<std::string>();
				Polycode::String file = (*it)["file"].as<std::string>();

				if(id.length() > 0 && file.length() > 0)			
					data.insert(std::make_pair(id, file));
			}
		}

	private:
		std::map<Polycode::String, Polycode::String> data;
};