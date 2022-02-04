#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
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
	switch (tickCount) {
	case 60:
		cout << "one";
		break;
	case 120:
		cout << "two";
		break;
	case 180:
		cout << "three";
		break;
	case 240:
		cout << "four";
		break;
	}

	if (tickCount == 300) {
		cout << "game tick: " << tickCount << endl;
		exit(0);
	}
	tickCount++;
}

void begin_updateLoop(function<void(void)> func, unsigned int interval) {
	start();

	thread([func, interval]()
		{
			while (true)
			{
				auto x = chrono::steady_clock::now() + chrono::milliseconds(interval);
				func();
				this_thread::sleep_until(x);
			}
		}).detach();
}

int main() {
	begin_updateLoop(update, 16);
	while (true);
}