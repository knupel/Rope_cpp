#include "../src/rope.hpp"

#include <iostream>
#include <cstdio>



int main() {
	Rope rope;
	std::cout << "r.colorModeA:" << rope.colorModeA << std::endl;

	// int colour = rope.color(255,0,0);
	int colour = rope.color(255,255,0);
	rope.colorMode(rope.HSB,1,1,1,1);
	std::cout << "colour: " << colour << std::endl;
	std::cout << "rgba: [ " << rope.red() <<  ", " << rope.gre() <<  ", " << rope.blu() <<  ", " << rope.alp() <<  " ]" << std::endl;
}