#pragma once

#include "../../Shape/Shape.h"

namespace Conphics
{
	class AlphabetFactory
	{
	private:
		AlphabetFactory();

	public:
		static Shape Generate(char c);
	};
}