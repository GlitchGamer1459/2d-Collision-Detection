#include <chrono>
#include <thread>
#include <functional>
using namespace std;

void begin_updateLoop(function<void(void)> func, unsigned int interval) {
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

void begin_updateLoop(function<void(void)> prereqFunc, function<void(void)> func, unsigned int interval) {
	prereqFunc();

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