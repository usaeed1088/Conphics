#include "Console.h"

#include <iostream>
#include <Windows.h>

namespace Conphics
{
	Console::Console(Resolution resolution):
		Screen(resolution)
	{
		BrightnessLevels.push_back(' ');
		BrightnessLevels.push_back('-');
		BrightnessLevels.push_back(':');
		BrightnessLevels.push_back('|');
		BrightnessLevels.push_back('=');
		BrightnessLevels.push_back('o');
		BrightnessLevels.push_back('O');
		BrightnessLevels.push_back('X');
		BrightnessLevels.push_back('&');
		BrightnessLevels.push_back('%');
		BrightnessLevels.push_back('$');
		BrightnessLevels.push_back('#');
	}

	Console::~Console()
	{

	}


	void Console::Update()
	{
		Pixels& pixels = GetPixels();

		for (int row = 0; row < pixels.size(); row++)
		{
			for (int col = 0; col < pixels[row].size(); col++)
			{
				if (!pixels[row][col].Updated)
				{
					continue;
				}

				MoveCursor(row, col);
				std::cout << BrightnessLevels[pixels[row][col].Value];
				pixels[row][col].Updated = false;
			}

			//std::cout << std::endl;
		}
	}

	void Console::MoveCursor(int row, int col)
	{
		// Untested, but simple enough it should at least be close to reality...
		COORD pos = { col, row };
		HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(output, pos);
	}

	void Console::SetConsoleSize(int height, int width)
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions

		MoveWindow(console, r.left, r.top, width, height, TRUE); // 800 width, 100 height
	}
}