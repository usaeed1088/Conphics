#include <Screen/Console/Console.h>
#include <Canvas/Freestyle/FreestyleCanvas.h>
#include <Canvas/Grid/GridCanvas.h>
#include <Canvas/Text/TextCanvas.h>

using namespace Conphics;

int main(int argc, char* argv[])
{
	Resolution ScreenResolution(60, 200);
	Console console(ScreenResolution);

	FreestyleCanvas freestyleCanvas(Dimensions(5, 200), Point(0, 0), console);
	GridCanvas gridCanvas(Dimensions(20, 200), Resolution(2, 10), Point(30, 0), console);
	TextCanvas textCanvas(Dimensions(16, 200), Point(6, 0), console);

	Shape shape(5, std::vector<bool>(200, true));

	freestyleCanvas.Draw(shape, Point(0, 0));
	freestyleCanvas.Draw(shape, Point(5, 5));

	gridCanvas.Draw(shape, Point(0, 0));
	gridCanvas.Draw(shape, Point(1, 1));

	std::string data("AAAA");
	textCanvas.Write(data);

	return 0;
}