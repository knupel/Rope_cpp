#include "../rope/template/utils/r_utils.hpp"
#include "../rope/template/vec/vec2.hpp"

#include <iostream>
#include <cstdio>



int main() {
	vec2<double> a(0,0.5);
	vec2<double> b(0,1.0);
	std::cout << dist_on_sphere(a.x(), a.y(), b.x(), b.y(), 10.0) << std::endl;

	std::cout << " random(0, 10): " << random(0, 10) << std::endl;
	std::cout << " random(0, 10): " << random(0, 10) << std::endl;
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::cout << " random(0, 10, generator): " << random(0, 10, generator) << std::endl;

}