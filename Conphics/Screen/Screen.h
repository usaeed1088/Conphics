#pragma once

#include "../Includes/Resolution.h"
#include "../Includes/Point.h"

#include <vector>

namespace Conphics
{
	class Screen
	{
	protected:
		typedef std::vector<std::vector<bool>> Pixels;

	private:
		Resolution m_Resolution;
		Pixels m_Pixels;

	protected:
		Screen(Resolution resolution);
		virtual ~Screen();

	private:
		friend class Canvas;
	public: // For testing only
		void UpdatePixel(Point point, bool value);

	protected:
		const Pixels& GetPixels() const;
	public: // For testing only
		virtual void Update() = 0;
	};
}