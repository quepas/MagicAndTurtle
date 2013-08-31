#include "Spell.h"

using namespace Polycode;

const String Spell::CAST_SPELL = "cast_spell";

Spell::Spell( const Polycode::String& filename, int width, int height )
	:	ScreenSprite(filename, width, height)
{

}

Spell::~Spell()
{

}
