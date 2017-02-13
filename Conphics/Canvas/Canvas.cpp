#include "Canvas.h"

namespace Conphics
{
	Canvas::Canvas(Type type, Resolution resolution, Point placement, Screen& screen) :
		m_Type(type),
		m_Resolution(resolution),
		m_Placement(placement),
		m_Screen(screen)
	{
	}

	Canvas::~Canvas()
	{
	}

	void Canvas::Draw()
	{
		m_Screen.Update();
	}
}