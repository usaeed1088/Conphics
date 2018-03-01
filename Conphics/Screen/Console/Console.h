#pragma once

#include "../Screen.h"

namespace Conphics
{
	class Console : public Screen
	{
	private:
		std::vector<std::uint8_t> BrightnessLevels;

	public:
		Console(Resolution resolution);
		~Console() override;

	public:
		void Update() override;

	private:
		void MoveCursor(int row, int col);
		void SetConsoleSize(int height, int width);
	};
}