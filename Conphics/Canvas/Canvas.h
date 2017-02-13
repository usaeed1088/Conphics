#pragma once

#include "../Includes/Resolution.h"
#include "../Includes/Point.h"
#include "../Screen/Screen.h"

namespace Conphics
{
	class Canvas
	{
	public:
		enum class Type : unsigned char
		{
			Unknown,
			Freestyle,
			Grid,
			Text,
		};

	private:
		Type m_Type;
		Resolution m_Resolution;
		Point m_Placement;

	private:
		Screen& m_Screen;

	protected:
		Canvas(Type type, Resolution resolution, Point placement, Screen& screen);
		virtual ~Canvas();

	public:
		void Draw();
	};
}