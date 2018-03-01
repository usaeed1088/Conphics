#pragma once

#include "../Shape.h"

#include "../../Includes/Point.h"

#include "../../Canvas/Canvas.h"

namespace Conphics
{
	class SmartShape : public Shape
	{
	public:
		enum class Direction : std::uint8_t
		{
			Right,
			Down,
			Left,
			Up,
		};

		enum class Flip : std::uint8_t
		{
			Vertical,
			Horizontal,
		};

	private:
		Canvas* m_Canvas;
		Point m_Offset;

	public:
		SmartShape(Canvas* canvas, Point offset);

		void Move(Direction direction, int16_t delta);
		//void Flip(Flip direction);

	private:
		void ClearSelf();
		void Rotate();
	};
}