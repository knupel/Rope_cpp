#include "../src/utils/r_utils.hpp"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <ctime>

void constrain_clamp_test() {
	float a = random(-10,10);
	std::cout << "constrain(" << a << ",-5,5): " << constrain<float>(a,-5,5) << std::endl;
	std::cout << "clamp(" << a << ",-5,5): " << clamp<float>(a,-5,5) << std::endl;
	a = -100;
	std::cout << "a: " << a << std::endl;
	constrain<float>(a,-5,5);
	std::cout << "a = constrain(" << a << ",-5,5): " << a << std::endl;
	double b = random_double(-10,10);
	std::cout << "constrain(" << b << ",-5,5): " << constrain<double>(b,-5,5) << std::endl;
	std::cout << "clamp(" << b << ",-5,5): " << clamp<double>(b,-5,5) << std::endl;
	int i = random_int(-10,10);
	std::cout << "constrain(" << i << ",-5,5): " << constrain<int>(i,-5,5) << std::endl;
	std::cout << "clamp(" << i << ",-5,5): " << clamp<int>(i,-5,5) << std::endl;	
}

int main() {
	constrain_clamp_test();
}