#pragma once

#include "Spell.h"
#include "Player.h"

class SpellFactory
{
	public:		

		static Spell* createSpell(Spell::TYPE type);
		static Spell* createAndCastSpell(Spell::TYPE type, Player* owner);		
	private:
		SpellFactory() {}
		SpellFactory(const SpellFactory&) {}
		SpellFactory& operator=(const SpellFactory&) {}

};