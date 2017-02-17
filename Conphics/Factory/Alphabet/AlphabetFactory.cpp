#include "AlphabetFactory.h"

namespace Conphics
{
	const int AlphabetFactory::CHARACTER_WIDTH	= 8;
	const int AlphabetFactory::CHARACTER_HEIGHT	= 8;

	AlphabetFactory::AlphabetFactory()
	{

	}

	Shape AlphabetFactory::Generate(char c)
	{
		Shape shape(CHARACTER_HEIGHT, std::vector<bool>(CHARACTER_WIDTH, false));

		switch (c)
		{
		case 'A':
			shape[0] = std::vector<bool>{ 0,0,0,0,0,0,0,0 };	// 0 0 0 1 1 0 0 0
			shape[1] = std::vector<bool>{ 0,0,1,1,1,1,0,0 };	// 0 0 0 1 1 0 0 0
			shape[2] = std::vector<bool>{ 0,1,0,0,0,0,1,0 };	// 0 0 0 1 1 0 0 0
			shape[3] = std::vector<bool>{ 0,1,0,0,0,0,1,0 };	// 0 0 0 1 1 0 0 0
			shape[4] = std::vector<bool>{ 0,1,1,1,1,1,1,0 };	// 0 0 0 1 1 0 0 0
			shape[5] = std::vector<bool>{ 0,1,0,0,0,0,1,0 };	// 0 0 0 1 1 0 0 0
			shape[6] = std::vector<bool>{ 0,1,0,0,0,0,1,0 };	// 0 0 0 1 1 0 0 0
			shape[7] = std::vector<bool>{ 0,1,0,0,0,0,1,0 };	// 0 0 0 1 1 0 0 0
			break;
		}

		return shape;
	}
}