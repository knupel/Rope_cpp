#include "../rope/template/utils/r_utils.hpp"
#include "../rope/rope_functions.hpp"
#include "../rope/template/vec/vec4.hpp"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <ctime>
#include <limits>


void constrain_clamp_test();
void random_test();



int main(int argc, const char * argv[]) {

	constrain_clamp_test();
	random_test();
}








void constrain_clamp_test() {
	std::cout << "\nvoid constrain_clamp_test()" << std::endl;
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

void random_test() {
	std::cout << "\nvoid random_test()" << std::endl;
	std::cout << "random_double(-10,10): " << random_double(-10,10) << std::endl;
	std::cout << "random_int(-10,10): " << random_int(-10,10) << std::endl;
	std::cout << "random_bool(): " << random_bool() << std::endl;

	std::random_device seed;
	std::default_random_engine generator(seed());
  
  long double ld_min = std::numeric_limits<long double>::min();
  long double ld_max = std::numeric_limits<long double>::max();
	std::cout << "random_long_double(ld_min, ld_max, generator): " << random_long_double(ld_min, ld_max, generator) << std::endl;

	for(int i = 0 ; i < 1000 ; i++) {
		std::cout << "random_int(10): " << random_int(10) << std::endl;
	}
}