#include "../rope/class/R_Body.hpp"

#include <iostream>
#include <cstdio>



int main() {
	R_Body::warning(true);
	R_Body a;
	R_Body b(1,2,3);
	std::cout << "b.pos(): " << b.pos() << std::endl;
	std::cout << "instance: " << R_Body::get_instance() << std::endl;
	b.size(2);
	b.dir(0.5);
	b.speed(3.56);
	std::cout << "b.size(): " << b.size() << std::endl;
	std::cout << "b.dir(): " << b.dir() << std::endl;
	std::cout << "b.speed(): " << b.speed() << std::endl;
	long double ld = 3.5;
	b.size(ld);
	std::cout << "b.size(): " << b.size() << std::endl;
	bool is = true;
	b.size(is);
	std::cout << "b.size(): " << b.size() << std::endl;

}