#include "../src/rope.hpp"

#include <iostream>
#include <cstdio>



int main() {
	Rope r;
  r.colorMode(r.RGB,255);
	std::cout << "colorMode(): " << r.colorMode() << std::endl;
	r.color(r.ORANGE);
	// r.color(255,125,0);
	std::cout << "orange int: " << r.ORANGE  << std::endl;
	std::cout << "orange split: " << r.red() << ", " <<  r.gre() << ", " << r.blu()  << std::endl;


	std::cout << "r.colorModeA:" << r.colorModeA << std::endl;

	// int colour = rope.color(255,0,0);
	int colour = r.color(255,255,0);
	std::cout << "colorMode(): " << r.colorMode() << std::endl;
	r.colorMode(r.HSB,1,1,1,1);
	std::cout << "colorMode(): " << r.colorMode() << std::endl;
	std::cout << "colour: " << colour << std::endl;
	std::cout << "rgba: " << r.red() <<  ", " << r.gre() <<  ", " << r.blu() <<  ", " << r.alp() << std::endl;
}