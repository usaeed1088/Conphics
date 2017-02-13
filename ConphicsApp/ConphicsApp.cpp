#include <Screen/Console/Console.h>
#include <Canvas/Freestyle/FreestyleCanvas.h>

int main(int argc, char* argv[])
{
	Conphics::Resolution ScreenResolution(60, 200);
	Conphics::Console console(ScreenResolution);

	Conphics::Dimensions CanvasDimension(10, 10);
	Conphics::Point CanvasPlacement(0, 0);
	Conphics::FreestyleCanvas freestyleCanvas(CanvasDimension, CanvasPlacement, console);

	Conphics::Shape shape(1, std::vector<bool>(10, true));
	Conphics::Shape shape2(10, std::vector<bool>(1, true));

	freestyleCanvas.Draw(shape);
	freestyleCanvas.Draw(shape2);

	return 0;
}