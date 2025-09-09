/**
* color test
* 2020-2020
* v 0.2.0
*/
#include "../rope/rope.hpp"

#include <iostream>
#include <cstdio>

void list_constants();

Rope *Rope::instance = 0;

int main() {
	list_constants();
}





void list_constants() {
	Rope *r = r->get_instance();
  std::cout << "Rope instance adresse" << r->get_instance() << std::endl;
  // a travailler
  // std::cout << "Rope instance id" << (r->get_instance()) << std::endl;
  std::cout << "Constante Rope Version " << r->ROPE_VERSION << std::endl;

  std::cout << "PI " << r->PI << std::endl;
  std::cout << "NORT " << r->NORTH << std::endl;
  std::cout << "ROUGE " << r->ROUGE << std::endl;
}





