#include "SmartShape.h"

namespace Conphics
{
	SmartShape::SmartShape(Canvas* canvas, Point offset):
		m_Canvas(canvas),
		m_Offset(offset)
	{

	}

	void SmartShape::Move(Direction direction, int16_t delta)
	{
		if (delta < 0)
		{
			return;
		}

		ClearSelf();

		switch (direction)
		{
		case Direction::Left:
			m_Offset.Col -= delta;
			break;
		case Direction::Right:
			m_Offset.Col += delta;
			break;
		case Direction::Up:
			m_Offset.Row -= delta;
			break;
		case Direction::Down:
			m_Offset.Row += delta;
			break;
		default:
			break;
		}

		m_Canvas->Draw(*this, m_Offset);
	}

	void SmartShape::ClearSelf()
	{
		// This function only clears the drawn area on the canvas
		// That's why we create an empty copy of this shape and draw it over
		Shape shape;
		Shape::Pixels pixels = GetPixels();
		for (int i = 0; i < pixels.size(); i++)
		{
			shape.AddRow(std::vector<std::uint8_t>(pixels[i].size(), 0));
		}
		m_Canvas->Draw(shape, m_Offset);
	}

	/*void SmartShape::Flip(Flip direction);
	{
		switch (direction)
		{

		}
		Rotate();
	}*/

	void SmartShape::Rotate()
	{
		Shape::Pixels newPixels;
		Shape::Pixels pixels = GetPixels();
		std::int32_t index = 0;
		for (int r = pixels.size() - 1; r >= 0; r--)
		{
			std::vector<std::uint8_t> row = pixels[r];
			if (newPixels.size() <= row.size())
			{
				newPixels.resize(row.size());
			}
			for (int c = 0; c<row.size(); c++)
			{
				if (newPixels[c].size() != index)
				{
					for (int i = 0; i<index; i++)
					newPixels[c].push_back(0);
				}
				newPixels[c].push_back(row[c]);
			}
			index++;
		}
		OverwritePixels(newPixels);
	}
}