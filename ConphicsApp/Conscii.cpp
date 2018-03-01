#include <Screen/Console/Console.h>
#include <Canvas/Freestyle/FreestyleCanvas.h>
#include <Canvas/Grid/GridCanvas.h>
#include <Canvas/Text/TextCanvas.h>

#include <Shape/SmartShape/SmartShape.h>

#include <thread>

using namespace Conphics;

int main(int argc, char* argv[])
{
	Resolution ScreenResolution(60, 200);
	Console console(ScreenResolution);

	FreestyleCanvas freestyleCanvas(Dimensions(60, 200), Point(0, 0), console);

	SmartShape shape1(&freestyleCanvas, Point(0,0));
	SmartShape shape2(&freestyleCanvas, Point(59, 199));

	shape1.AddRow(std::vector<uint8_t>{1, 2, 3, 4, 5});
	shape1.AddRow(std::vector<uint8_t>{5, 4, 3, 2, 1});

	shape2.AddRow(std::vector<uint8_t>{1, 2, 3, 4, 5});
	shape2.AddRow(std::vector<uint8_t>{5, 4, 3, 2, 1});
	
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 200; j+=10)
		{
			shape1.Move(SmartShape::Direction::Right, 10);
			shape2.Move(SmartShape::Direction::Left, 10);
			console.Update();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}

		shape1.Move(SmartShape::Direction::Left, 200);
		shape1.Move(SmartShape::Direction::Down, 1);

		shape2.Move(SmartShape::Direction::Right, 200);
		shape2.Move(SmartShape::Direction::Up, 1);
	}

	return 0;
}