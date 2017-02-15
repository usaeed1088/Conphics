#pragma once

#include "../Includes/Dimensions.h"
#include "../Includes/Point.h"
#include "../Includes/Shape.h"

#include "../Screen/Screen.h"

namespace Conphics
{
	class Canvas
	{
	public:
		enum class Type : unsigned char
		{
			Unknown,
			Freestyle,
			Grid,
			Text,
		};

	protected:
		struct Boundary
		{
			Boundary(int minHeight, int maxHeight, int minWidth, int maxWidth):
				MinHeight(minHeight), MaxHeight(maxHeight), MinWidth(minWidth), MaxWidth(maxWidth)
			{}
			int MinHeight;
			int MaxHeight;
			int MinWidth;
			int MaxWidth;
		};

	private:
		Type m_Type;
		Dimensions m_Dimensions;
		Point m_Placement;
		Boundary m_Boundary;

	private:
		Screen& m_Screen;

	protected:
		Canvas(Type type, Dimensions dimensions, Point placement, Screen& screen);
		virtual ~Canvas();

	public:
		virtual void Draw(const Shape& shape, Point offset = Point(0,0)) = 0;

	protected:
		Point Placement();
		void UpdatePixel(Point pixel, bool value);
		void UpdateScreen();
	};
}