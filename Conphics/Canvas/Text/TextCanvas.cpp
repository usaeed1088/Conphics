#include "TextCanvas.h"

#include "../../Factory/Alphabet/AlphabetFactory.h"

namespace Conphics
{
	TextCanvas::TextCanvas(Dimensions dimensions, Point placement, Screen& screen):
		Canvas(Canvas::Type::Text, dimensions, placement, screen)
	{

	}

	TextCanvas::~TextCanvas()
	{

	}

	void TextCanvas::Write(const std::string & data)
	{
		for (int i = 0; i < data.length(); i++)
		{
			Shape shape = AlphabetFactory::Generate(data[i]);

			Draw(shape, Point(0, i*shape[0].size()));
		}

		UpdateScreen();
	}

	void TextCanvas::Draw(const Shape& shape, Point offset)
	{
		for (int row = 0; row < shape.size(); row++)
		{
			for (int col = 0; col < shape[row].size(); col++)
			{
				UpdatePixel(Point(row + offset.Row + Placement().Row, col + offset.Col + Placement().Col), shape[row][col]);
			}
		}
	}
}

