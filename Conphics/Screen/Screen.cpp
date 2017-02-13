#include "Screen.h"

namespace Conphics
{
	Screen::Screen(Resolution resolution) :
		m_Resolution(resolution),
		m_Pixels(resolution.Rows, std::vector<bool>(resolution.Cols))
	{
	}

	Screen::~Screen()
	{
	}

	void Screen::UpdatePixel(Point point, bool value)
	{
		if (point.Row >= m_Resolution.Rows) { return; }
		if (point.Col >= m_Resolution.Cols) { return; }

		m_Pixels[point.Row][point.Col] = value;
	}

	const Screen::Pixels& Screen::GetPixels() const
	{
		return m_Pixels;
	}
}