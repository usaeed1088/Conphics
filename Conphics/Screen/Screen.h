#pragma once

#include "../Includes/Resolution.h"
#include "../Includes/Point.h"

#include <vector>

namespace Conphics
{
	class Screen
	{
	private:
		friend class Canvas;

	protected:
		typedef std::vector<std::vector<bool>> Pixels;

	private:
		Resolution m_Resolution;
		Pixels m_Pixels;

	protected:
		Screen(Resolution resolution);
		virtual ~Screen();

	private:
		void UpdatePixel(Point point, bool value);

	protected:
		const Pixels& GetPixels() const;
		virtual void Update() = 0;
	};
}