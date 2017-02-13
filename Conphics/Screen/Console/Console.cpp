#include "Console.h"

#include <iostream>

namespace Conphics
{
	const char Console::FillCharacter('X');
	const char Console::EmptyCharacter(' ');

	Console::Console(Resolution resolution):
		Screen(resolution)
	{

	}

	Console::~Console()
	{

	}


	void Console::Update()
	{
		const Pixels& pixels = GetPixels();

		for (std::vector<bool> row : pixels)
		{
			for (bool value : row)
			{
				char c = FillCharacter;
				if (!value) { c = EmptyCharacter; }
				std::cout << c;
			}

			std::cout << std::endl;
		}
	}
}