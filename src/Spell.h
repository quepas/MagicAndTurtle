#pragma once

#include <PolyScreenSprite.h>
#include <PolyGlobals.h>

#include "GlobalDef.h"

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

		struct Parameters
		{
			Number range;
			Number intensity;			
			uint32 time;
			Polycode::String file;
			uint16 width;
			uint16 height;
			Polycode::String castSeq;
			Number castTime;
		};

		Spell(const Polycode::String& filename, uint16 width, uint16 height);
		~Spell();		

		Parameters getParameters() const { return parameters; }
		void setParameters(Parameters val) { parameters = val; }

		static const Polycode::String CAST_SPELL;
	private:
		Parameters parameters;				
};