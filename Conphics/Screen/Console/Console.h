#pragma once

#include "../Screen.h"

namespace Conphics
{
	class Console : public Screen
	{
	private:
		static const char FillCharacter;
		static const char EmptyCharacter;

	public:
		Console(Resolution resolution);
		~Console() override;

	private:
		void Update() override;
	};
}