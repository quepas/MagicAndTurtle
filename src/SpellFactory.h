#pragma once

#include <map>

#include "Spell.h"
#include "Player.h"

class SpellFactory
{
	public:		

		static Spell* createSpell(Spell::TYPE type);		
		static Spell* createAndCastSpell(Spell::TYPE type, Player* owner);		

		static void parseConfiguration(Polycode::String file);
	private:
		SpellFactory() {}
		SpellFactory(const SpellFactory&) {}
		SpellFactory& operator=(const SpellFactory&) {}

		static std::map<Spell::TYPE, Spell::Parameters> spellData;

};