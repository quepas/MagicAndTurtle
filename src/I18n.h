#pragma once

#include <map>
#include <PolyString.h>
#include <yaml-cpp/yaml.h>

class I18n
{
public:
	enum LANG_CODE 
	{
		PL,
		EN		
	};	

	I18n();
	~I18n();

	void parseFile(Polycode::String name);	
	Polycode::String get(Polycode::String key);
	Polycode::String get(Polycode::String key, LANG_CODE lng);

	static void setCurrentLng(LANG_CODE lng) { currentLng = lng; }
	static LANG_CODE getCurrentLng() { return currentLng; }
private:
	struct I18n_value
	{
		Polycode::String key;
		std::map<LANG_CODE, Polycode::String> values;
	};

	std::vector<I18n_value*> values;
	static LANG_CODE currentLng;
	
	void insertLngValue(I18n_value* value, LANG_CODE lng, YAML::iterator it);
	Polycode::String convertLngEnumToString(LANG_CODE lng);
};