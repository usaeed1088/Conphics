#include "GridCanvas.h"

namespace Conphics
{
	GridCanvas::GridCanvas(Dimensions dimensions, GridResolution gridResolution, Point placement, Screen& screen):
		Canvas(Type::Grid, dimensions, placement, screen),
		m_GridResolution(gridResolution),
		m_UnitDimensions(Dimensions(dimensions.Height/ gridResolution.Rows, dimensions.Width/gridResolution.Cols))
	{

	}

	GridCanvas::~GridCanvas()
	{

	}

	void GridCanvas::Draw(const Shape& shape, Point offset)
	{
		Boundary boundary = DetermineUnitBoundary(offset);

		Shape::Pixels pixels = shape.GetPixels();

		for (int row = 0; row < pixels.size(); row++)
		{
			for (int col = 0; col < pixels[row].size(); col++)
			{
				Point p(boundary.MinHeight + row, boundary.MinWidth + col);
				if (p.Row >= boundary.MaxHeight) { continue; }
				if (p.Col >= boundary.MaxWidth) { continue; }
				UpdatePixel(p, pixels[row][col]);
			}
		}
	}

	Canvas::Boundary GridCanvas::DetermineUnitBoundary(Point offset)
	{
		Point base = Placement();

		int MinRow = base.Row + (offset.Row*m_UnitDimensions.Height);
		int MinCol = base.Col + (offset.Col*m_UnitDimensions.Width);
		int MaxRow = MinRow + m_UnitDimensions.Height;
		int MaxCol = MinCol + m_UnitDimensions.Width;

		return Boundary(MinRow, MaxRow, MinCol, MaxCol);
	}
}