#pragma once

namespace Conphics
{
	struct Resolution
	{
		Resolution(int rows, int cols) :
			Rows(rows), Cols(cols) {}
		int Rows;
		int Cols;
	};
}