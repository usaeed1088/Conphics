#include "AlphabetFactory.h"

namespace Conphics
{
	AlphabetFactory::AlphabetFactory()
	{

	}

	Shape AlphabetFactory::Generate(char c)
	{
		Shape shape;

		switch (c)
		{
		case 'A':
			shape.AddRow(std::vector<std::uint8_t>{ 0,0,0,0,0,0,0,0 });	// 0 0 0 1 1 0 0 0
			shape.AddRow(std::vector<std::uint8_t>{ 0,0,7,7,7,7,0,0 });	// 0 0 0 1 1 0 0 0
			shape.AddRow(std::vector<std::uint8_t>{ 0,6,0,0,0,0,6,0 });	// 0 0 0 1 1 0 0 0
			shape.AddRow(std::vector<std::uint8_t>{ 0,5,0,0,0,0,5,0 });	// 0 0 0 1 1 0 0 0
			shape.AddRow(std::vector<std::uint8_t>{ 0,4,4,4,4,4,4,0 });	// 0 0 0 1 1 0 0 0
			shape.AddRow(std::vector<std::uint8_t>{ 0,3,0,0,0,0,3,0 });	// 0 0 0 1 1 0 0 0
			shape.AddRow(std::vector<std::uint8_t>{ 0,2,0,0,0,0,2,0 });	// 0 0 0 1 1 0 0 0
			shape.AddRow(std::vector<std::uint8_t>{ 0,1,0,0,0,0,1,0 });	// 0 0 0 1 1 0 0 0
			break;
		}

		return shape;
	}
}