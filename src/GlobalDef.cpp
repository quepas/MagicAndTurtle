#include "GlobalDef.h"

double _round( double val )
{
	return val < 0
		? ceil( val - 0.5 )
		: floor( val + 0.5 );
}