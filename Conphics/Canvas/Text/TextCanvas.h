#pragma once

#include "../Canvas.h"

#include <string>

namespace Conphics
{
	class TextCanvas : public Canvas
	{
	public:
		TextCanvas(Dimensions dimensions, Point placement, Screen& screen);
		~TextCanvas() override;

		void Write(const std::string& data);

		void Draw(const Shape& shape, Point offset) override;
	};
}