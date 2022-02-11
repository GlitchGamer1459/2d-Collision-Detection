#include <iostream>
#include "engine.h"
using namespace std;

int tickCount = 0;

void start() {
	tickCount++;
}

void update() {

	if (tickCount == 300) {
		cout << "game tick: " << tickCount << endl;
		exit(0);
	}
	tickCount++;
}

int main() {
	int framerate = 60;

	begin_updateLoop(start, update, (1000 / framerate));
	while (true);
}