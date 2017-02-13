#pragma once

namespace Conphics
{
	struct Dimensions
	{
		Dimensions(int height, int width) :
			Height(height), Width(width) {}
		int Height;
		int Width;
	};
}