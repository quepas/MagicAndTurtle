#pragma once

#include <PolyColor.h>
#include <PolyVector2.h>

class TransitionUtil
{
	public:

		static Polycode::Color calculateColorDiff(
			Polycode::Color base, Polycode::Color dest, Number intensity);
		static Polycode::Vector2 calculatePositionDiff(
			Polycode::Vector2 start, Polycode::Vector2 end, Number intensity);

	private:
		TransitionUtil() {}
		TransitionUtil(const TransitionUtil&) {}
		TransitionUtil& operator=(const TransitionUtil&) {}
};