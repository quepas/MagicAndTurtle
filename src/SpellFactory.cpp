#include "SpellFactory.h"
#include <iostream>
#include <yaml-cpp/yaml.h>

using namespace Polycode;

SpellFactory::SpellFactory()
{
	spellData = std::map<std::string, Spell::Parameters*>();
}

Spell* SpellFactory::createSpell( Spell::TYPE type )
{
	Spell* fireball = nullptr;	
	Spell::Parameters* parameters = nullptr;

	switch(type)
	{
	case Spell::FIRE_BALL:
		parameters = spellData[ENUM_TO_STR(Spell::FIRE_BALL)];
		break;
	case Spell::FIRE_BLAST:
		parameters = spellData[ENUM_TO_STR(Spell::FIRE_BLAST)];
		break;
	case Spell::FROST_BALL:
		parameters = spellData[ENUM_TO_STR(Spell::FROST_BALL)];
		break;
	case Spell::TELEPORT:
		parameters = spellData[ENUM_TO_STR(Spell::TELEPORT)];
		break;
	}	

	return createSpellUsingParameters(parameters);
}

void SpellFactory::parseConfiguration( String file )
{	
	YAML::Node spellYAML = YAML::LoadFile(file.contents);	

	for( auto it = spellYAML.begin(); it != spellYAML.end(); ++it) 
	{
		Spell::Parameters* parameters = new Spell::Parameters();
		String id = (*it)["id"].as<std::string>();
		
		if( id.size() > 0 )
		{
			parameters -> range = (*it)["range"].as<Number>();			
			parameters -> intensity = (*it)["intensity"].as<Number>();			
			parameters -> time = (*it)["time"].as<uint32>();			
			parameters -> file = (*it)["file"].as<std::string>();
			parameters -> width = (*it)["width"].as<uint16>();
			parameters -> height = (*it)["height"].as<uint16>();
			parameters -> castSeq = (*it)["castSeq"].as<std::string>();
			parameters -> castTime = (*it)["castTime"].as<Number>();
		}				
		spellData.insert(std::pair<std::string, Spell::Parameters*>(getFullSpellId(id), parameters));
	}
}

std::string SpellFactory::getFullSpellId( Polycode::String id )
{	
	return std::string("Spell::") + id.getSTLString();
}

Spell* SpellFactory::createSpellUsingParameters( Spell::Parameters* parameters )
{	
	Spell* spell = nullptr;
	if(parameters)
	{
		spell = new Spell(parameters->file, parameters->width, parameters->height);
		spell -> addAnimation(Spell::CAST_SPELL, parameters->castSeq, parameters->castTime);
		spell -> playAnimation(Spell::CAST_SPELL, 0, false);
	}	
	return spell;
}
