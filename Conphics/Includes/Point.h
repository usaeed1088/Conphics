#pragma once

namespace Conphics
{
	struct Point
	{
		Point(int row, int col) :
			Row(row), Col(col) {}
		int Row;
		int Col;
	};
}