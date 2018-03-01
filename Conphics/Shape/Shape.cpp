#include "Shape.h"

namespace Conphics
{
	Shape::Shape() :
		m_Pixels(),
		m_Updated(false)
	{

	}

	Shape::~Shape()
	{

	}

	void Shape::AddRow(std::vector<std::uint8_t> row)
	{
		m_Pixels.push_back(row);
	}

	bool Shape::Updated()
	{
		return m_Updated;
	}

	const Shape::Pixels& Shape::GetPixels() const
	{
		return m_Pixels;
	}

	void Shape::OverwritePixels(const Pixels& pixels)
	{
		m_Pixels = pixels;
	}
}