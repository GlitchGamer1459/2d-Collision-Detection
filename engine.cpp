#include <chrono>
#include <thread>
#include <functional>

void begin_updateLoop(std::function<void(void)> func, unsigned int interval) {
	std::thread([func, interval]()
		{
			while (true)
			{
				auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(interval);
				func();
				std::this_thread::sleep_until(x);
			}
		}).detach();
}

void begin_updateLoop(std::function<void(void)> prereqFunc, std::function<void(void)> func, unsigned int interval) {
	prereqFunc();

	std::thread([func, interval]()
		{
			while (true)
			{
				auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(interval);
				func();
				std::this_thread::sleep_until(x);
			}
		}).detach();
}