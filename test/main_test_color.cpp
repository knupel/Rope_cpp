#include "../src/rope.hpp"

#include <iostream>
#include <cstdio>



int main() {
	Rope rope;
	std::cout << "r.colorModeA:" << rope.colorModeA << std::endl;

	int colour = rope.color(0);
	std::cout << "colour: " << colour << std::endl;
	std::cout << "rgba: [ " << rope.red() <<  ", " << rope.gre() <<  ", " << rope.blu() <<  ", " << rope.alp() <<  " ]" << std::endl;
}