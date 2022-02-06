#pragma once
#include <chrono>
#include <thread>
#include <functional>

void begin_updateLoop(std::function<void(void)> func, unsigned int interval);
void begin_updateLoop(std::function<void(void)> prereqFunc, std::function<void(void)> func, unsigned int interval);