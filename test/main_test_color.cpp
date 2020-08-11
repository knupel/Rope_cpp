#include "../rope/rope.hpp"

#include <iostream>
#include <cstdio>



int main() {
	Rope r;
  r.colorMode(r.RGB,255);
	std::cout << "colorMode(): " << r.colorMode() << std::endl;
	r.color(r.NOISETTE);
	// r.color(255,125,0);
	std::cout << "r.NOISETTE int: " << r.NOISETTE  << std::endl;
	std::cout << "r.NOISETTE split RGB " << r.red() << ", " <<  r.gre() << ", " << r.blu()  << std::endl;
	std::cout << "r.NOISETTE split HSB " << r.hue() << ", " <<  r.sat() << ", " << r.bri()  << std::endl;


	// r.colorMode(r.RGB,1);
	// rgb a;
	// a.r = r.red();
	// a.g = r.gre();
	// a.b = r.blu();
	// std::cout << "orange split HSB: " <<  rgb_to_hsb(a).h << ", " <<  rgb_to_hsb(a).s << ", " << rgb_to_hsb(a).b  << std::endl;
	// hsb b;
	// b.h = 180;
	// b.s = 1.0;
	// b.b = 0.2;
	// std::cout << "hsb b split to RGB: " <<  hsb_to_rgb(b).r << ", " <<  hsb_to_rgb(b).g << ", " << hsb_to_rgb(b).b  << std::endl;
	// r.colorMode(r.HSB,1);


	std::cout << "r.colorModeA:" << r.colorModeA << std::endl;

	// int colour = rope.color(255,0,0);
	int colour = r.color(255,255,0);
	std::cout << "colorMode(): " << r.colorMode() << std::endl;
	r.colorMode(r.HSB,1,1,1,1);
	std::cout << "colorMode(): " << r.colorMode() << std::endl;
	std::cout << "colour: " << colour << std::endl;
	std::cout << "rgba: " << r.red() <<  ", " << r.gre() <<  ", " << r.blu() <<  ", " << r.alp() << std::endl;
}