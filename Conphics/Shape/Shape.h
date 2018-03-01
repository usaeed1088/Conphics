#pragma once

#include <vector>
#include <cstdint>

namespace Conphics
{
	class Shape
	{
	public:
		typedef std::vector<std::vector<std::uint8_t>> Pixels;

	private:
		Pixels m_Pixels;
		bool m_Updated;

	public:
		Shape();
		virtual ~Shape();

		void AddRow(std::vector<std::uint8_t> row);

		bool Updated();

		const Pixels& GetPixels() const;

	protected:
		void OverwritePixels(const Pixels& pixels);
	};
}