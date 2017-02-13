#include <Canvas\Canvas.h>
#include <Screen/Console/Console.h>

void Draw(int number, int Rows, int Cols, Conphics::Screen& screen)
{
	int index = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (index++ % number == 0) { screen.UpdatePixel(Conphics::Point(i, j), false); }
			else { screen.UpdatePixel(Conphics::Point(i, j), true); }
		}
	}

	screen.Update();
}

int main(int argc, char* argv[])
{
	const int Rows = 60;
	const int Cols = 200;
	Conphics::Console console(Conphics::Resolution(Rows, Cols));
	Conphics::Screen& screen = console;

	for (int i = 1; i <= 500; i++)
	{
		Draw(i, Rows, Cols, console);
	}

	return 0;
}