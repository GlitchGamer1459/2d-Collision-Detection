#pragma once
#include <chrono>
#include <thread>
#include <functional>
using namespace std;

void begin_updateLoop(function<void(void)> func, unsigned int interval);
void begin_updateLoop(function<void(void)> prereqFunc, function<void(void)> func, unsigned int interval);