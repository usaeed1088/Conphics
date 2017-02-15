#pragma once

#include "../Canvas.h"

namespace Conphics
{
	class GridCanvas : public Canvas
	{
	public:
		typedef Resolution GridResolution;

	private:
		Dimensions m_UnitDimensions;
		GridResolution m_GridResolution;

	public:
		GridCanvas(Dimensions dimensions, GridResolution gridResolution, Point placement, Screen& screen);
		~GridCanvas() override;

		void Draw(const Shape& shape, Point offset) override;

	private:
		Boundary DetermineUnitBoundary(Point offset);
	};
}