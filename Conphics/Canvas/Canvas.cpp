#include "Canvas.h"

namespace Conphics
{
	Canvas::Canvas(Type type, Dimensions dimensions, Point placement, Screen& screen) :
		m_Type(type),
		m_Dimensions(dimensions),
		m_Placement(placement),
		m_Screen(screen),
		m_Boundary(placement.Row, placement.Row + dimensions.Height, placement.Col, placement.Col + dimensions.Width)
	{
	}

	Canvas::~Canvas()
	{
	}

	Point Canvas::Placement()
	{
		return m_Placement;
	}

	void Canvas::UpdatePixel(Point pixel, bool value)
	{
		if (pixel.Col >= m_Boundary.MaxWidth) { return; }
		if (pixel.Col < m_Boundary.MinWidth) { return; }

		if (pixel.Row >= m_Boundary.MaxHeight) { return; }
		if (pixel.Row < m_Boundary.MinHeight) { return; }

		m_Screen.UpdatePixel(pixel, value);
	}

	void Canvas::UpdateScreen()
	{
		m_Screen.Update();
	}
}