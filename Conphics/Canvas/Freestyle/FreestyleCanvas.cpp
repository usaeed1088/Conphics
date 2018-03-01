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

	void FreestyleCanvas::Draw(const Shape& shape, Point offset)
	{
		Shape::Pixels pixels = shape.GetPixels();

		for (int row = 0; row < pixels.size(); row++)
		{
			for (int col = 0; col < pixels[row].size(); col++)
			{
				UpdatePixel(Point(row + offset.Row + Placement().Row, col + offset.Col + Placement().Col), pixels[row][col]);
			}
		}
	}
}