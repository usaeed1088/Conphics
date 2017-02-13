#include "FreestyleCanvas.h"

namespace Conphics
{
	FreestyleCanvas::FreestyleCanvas(Dimensions dimensions, Point placement, Screen& screen):
		Canvas(Canvas::Type::Freestyle, dimensions, placement, screen)
	{

	}

	FreestyleCanvas::~FreestyleCanvas()
	{

	}

	void FreestyleCanvas::Draw(const Shape& shape)
	{
		for (int row = 0; row < shape.size(); row++)
		{
			for (int col = 0; col < shape[row].size(); col++)
			{
				UpdatePixel(Point(row + Placement().Row, col + Placement().Col), shape[row][col]);
			}
		}

		UpdateScreen();
	}
}