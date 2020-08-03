// #include "../rope/template/utils/r_utils.hpp"
#include "../rope/template/math/r_geom.hpp"
#include "../rope/template/vec/vec2.hpp"

#include <iostream>
#include <cstdio>



int main() {
	vec2<double> a(0,0.5);
	vec2<double> b(0,1.0);
	std::cout << "dist_sphere<double>(a.x(), a.y(), b.x(), b.y(), 10.0): " << dist_sphere<double>(a.x(), a.y(), b.x(), b.y(), 10.0) << std::endl;
	std::cout << "dist_sphere<double>(a, b, 10.0): " << dist_sphere<double>(a, b, 10.0) << std::endl;

	float x = 0;
	float y = 0;
	float dir = 3.14;
	float radius = 21;
	coord_polar(x,y,dir,radius);
	std::cout << "coord_polar(T &x, T &y, T dir, T radius): " << x << " " << y << std::endl;

	std::cout << "coord_polar(T dir, T radius): " << coord_polar(dir,radius) << std::endl;
}