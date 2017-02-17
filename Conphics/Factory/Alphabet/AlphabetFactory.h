#pragma once

#include "../../Includes/Shape.h"

namespace Conphics
{
	class AlphabetFactory
	{
	private:
		static const int CHARACTER_WIDTH;
		static const int CHARACTER_HEIGHT;

	private:
		AlphabetFactory();

	public:
		static Shape Generate(char c);
	};
}