/**
* Constants Test
* 2025-2025
* v 0.1.0
*/
#include "../rope/rope.hpp"
#include <iostream>
#include <cstdio>

void list_constants();

Rope *Rope::instance = 0; // ce n'est pas une valeur, mais une adresse sans doute.

int main() {
	list_constants();
}


void list_constants() {
	Rope *r = r->get_instance();
  std::cout << "Rope instance adresse" << r->get_instance() << std::endl;
  // a travailler
  // std::cout << "Rope instance id" << (r->get_instance()) << std::endl;
  std::cout << "Constante Rope Version " << r->ROPE_VERSION << std::endl;
  
  // 	const float PI = 3.1415926535; constante orginale dans la librairie
  std::cout << "PI CONSTANTE " << r->PI << std::endl;
  std::cout << "PI " << 3.1415926535 << std::endl; // manque de chiffre après la virgule
  printf("PI float %f \n", r->PI); // affiche un de plus que le std::cout
  std::cout << "PI DIX MILLIARD " << r->PI * 10000000000 << std::endl;
  printf("PI MILLIARD float %f \n", r->PI * 10000000000); // une erreur dans à la fin après la 6em en mode float, mais  avec la constante en double c'est bon.
  std::cout << "PI DIX MILLIARD " << 31415926535 << std::endl;
  std::cout << "NORTH " << r->NORTH << std::endl;
  std::cout << "ROUGE " << r->ROUGE << std::endl;

  printf("BLANK %i \n", r->BLANK);

  printf("CORNER %i \n", r->CORNER);
  printf("CORNERS %i \n", r->CORNERS);

  printf("FLUID %i \n", r->FLUID);
  printf("MAGNETIC %i \n", r->MAGNETIC);
}





