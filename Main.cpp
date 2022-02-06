#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include "engine.h"
using namespace std;

class Target {
public:
	double x, y;
	double hitboxRadius = .5;

	Target(double xin, double yin) {
		x = xin;
		y = yin;
	}
};

class Rock {
public:
	double x, y, velocity, direction;
	double hitboxRadius = .1;

	Rock(double xin, double yin, double dirin, double velin) {
		x = xin;
		y = yin;
		velocity = velin;
		direction = dirin;
	}
};

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