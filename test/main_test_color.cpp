#include "../src/rope.hpp"

#include <iostream>
#include <cstdio>



int main() {
	Rope rope;
	std::cout << "r.colorModeA:" << rope.colorModeA << std::endl;
	int col = 213;
	float alpha = 50;
	float r = 255;
	float g = 0;
	float b = 0;
	float a = 255;
	int red_color = rope.color(r,g,b);
	std::cout << "red: " << red_color << std::endl;
	std::cout << "rgba: " << rope.red() << rope.gre() << rope.blu() << rope.alp() << std::endl;
}