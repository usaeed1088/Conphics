#include "Screen.h"

namespace Conphics
{
	Screen::Screen(Resolution resolution) :
		m_Resolution(resolution),
		m_Pixels(resolution.Rows, std::vector<Pixel>(resolution.Cols, Pixel(0, true)))
	{
	}

	Screen::~Screen()
	{
	}

	void Screen::UpdatePixel(Point point, std::uint8_t value)
	{
		if (point.Row >= m_Resolution.Rows) { return; }
		if (point.Col >= m_Resolution.Cols) { return; }

		m_Pixels[point.Row][point.Col].Value = value;
		m_Pixels[point.Row][point.Col].Updated = true;
	}

	Screen::Pixels& Screen::GetPixels()
	{
		return m_Pixels;
	}
}