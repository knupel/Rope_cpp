#include "../src/rope.hpp"

#include <iostream>
#include <cstdio>



int main() {
	int col = 213;
	float alpha = 50;
	colorCalcARGB(col, alpha);
	float r = 255;
	float g = 0;
	float b = 0;
	float a = 255;
	colorCalc(r,g,b,a);
	int red_color = color(r,g,b);
	std::cout << "red: " << red_color << std::endl;
	// std::cout << "rgba: " << calcR << calcG << calcB << calcA << std::endl;
}