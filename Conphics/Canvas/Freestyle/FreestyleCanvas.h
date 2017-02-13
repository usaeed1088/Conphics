#pragma once

#include "../Canvas.h"

namespace Conphics
{
	class FreestyleCanvas : public Canvas
	{
	public:
		FreestyleCanvas(Dimensions dimensions, Point placement, Screen& screen);
		~FreestyleCanvas() override;

		void Draw(const Shape& shape) override;
	};
}