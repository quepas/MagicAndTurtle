#pragma once

#include <PolyScreenSprite.h>

class Spell : public Polycode::ScreenSprite
{
	public:
		enum TYPE
		{
			FIRE_BALL,
			FIRE_BLAST,
			FROST_BALL,			
			TELEPORT
		};

		Spell(const Polycode::String& filename, int width, int height);
		~Spell();

		static const Polycode::String CAST_SPELL;
	private:
};