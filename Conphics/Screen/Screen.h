#pragma once

#include "../Includes/Resolution.h"
#include "../Includes/Point.h"

#include <vector>
#include <cstdint>

namespace Conphics
{
	class Screen
	{
	private:
		friend class Canvas;

	protected:
		struct Pixel
		{
			Pixel(std::uint8_t value, bool updated) :
				Value(value), Updated(updated)
			{
			}

			std::uint8_t Value;
			bool Updated;
		};
		typedef std::vector<std::vector<Pixel>> Pixels;

	private:
		Resolution m_Resolution;
		Pixels m_Pixels;

	protected:
		Screen(Resolution resolution);
		virtual ~Screen();

	private:
		void UpdatePixel(Point point, std::uint8_t value);

	protected:
		Pixels& GetPixels();

	public:
		virtual void Update() = 0;
	};
}