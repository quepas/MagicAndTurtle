#pragma once

#include <map>

#include "Spell.h"
#include "Player.h"

class SpellFactory
{
	public:		

		Spell* createSpell(Spell::TYPE type);		
		Spell* createAndCastSpell(Spell::TYPE type, Player* owner);		

		void parseConfiguration(Polycode::String file);

		static SpellFactory& getInstance()
		{
			static SpellFactory instance;
			return instance;
		}
	private:
		SpellFactory();
		SpellFactory(const SpellFactory&) {}
		SpellFactory& operator=(const SpellFactory&) {}

		std::map<std::string, Spell::Parameters*> spellData;

		std::string getFullSpellId(Polycode::String id);
		Spell* createSpellUsingParameters(Spell::Parameters* parameters);
};