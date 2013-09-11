#include "I18n.h"
#include <fstream>
#include "GlobalDef.h"

using namespace Polycode;

I18n::LANG_CODE I18n::currentLng = PL;

I18n::I18n()
{

}

I18n::~I18n()
{

}

void I18n::parseFile( String name )
{
	YAML::Node lngData = YAML::LoadFile(name.contents);
			
	for( auto it = lngData.begin(); it != lngData.end(); ++it ) 
	{	
		I18n_value* element = new I18n_value();
		String str = (*it)["id"].as<std::string>();

		// non-empty identifier
		if( str.size() > 0 ) 
		{
			element -> key = str;			
			insertLngValue(element, PL, it);
			insertLngValue(element, EN, it);			
			values.push_back(element);
		}		
	}
}

void I18n::insertLngValue( I18n_value* value, LANG_CODE lng, YAML::iterator it )
{
	String strLng = convertLngEnumToString(lng);	

	String keyValue = (*it)[strLng.getSTLString()].as<std::string>();
	if( keyValue.size() > 0 ) 
		value -> values.insert( std::pair<LANG_CODE, String>(lng, keyValue) );
}

Polycode::String I18n::convertLngEnumToString( LANG_CODE lng )
{
	switch(lng)
	{
	case PL:
		return ENUM_TO_LOWER_STR(PL);		
	case EN:
		return ENUM_TO_LOWER_STR(EN);		
	default:
		return ENUM_TO_LOWER_STR(PL);
	}
}

Polycode::String I18n::get( Polycode::String key )
{
	return get(key, currentLng);
}

Polycode::String I18n::get( Polycode::String key, LANG_CODE lng )
{
	for(auto it = values.begin(); it != values.end(); ++it)
	{ 		
		if((*it)->key == key)
			return (*it) -> values[lng];
	}
	return NONE;
}

