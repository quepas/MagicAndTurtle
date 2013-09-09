#include "Spell.h"

using namespace Polycode;

const String Spell::CAST_SPELL = "cast_spell";

Spell::Spell( const Polycode::String& filename, uint16 width, uint16 height )
	:	ScreenSprite(filename, width, height)
{

}

Spell::~Spell()
{

}
