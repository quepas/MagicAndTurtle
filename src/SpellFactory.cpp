#include "SpellFactory.h"

Spell* SpellFactory::createSpell( Spell::TYPE type )
{
	Spell* fireball = nullptr;
	switch(type)
	{
		case Spell::FIRE_BALL:
			fireball = new Spell("res/particle/fireball.png", 250, 100);
			fireball -> addAnimation(Spell::CAST_SPELL, "1, 3, 5, 7, 9, 2, 4, 6, 8, 10", 0.15);
			fireball -> playAnimation(Spell::CAST_SPELL, 0, false);
			return fireball;
		case Spell::FIRE_BLAST:
			break;
		case Spell::FROST_BALL:
			break;
		case Spell::TELEPORT:
			break;
		default:
			return fireball;
	}
}
