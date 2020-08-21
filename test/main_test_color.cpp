/**
* color test
* 2020-2020
* v 0.2.0
*/
#include "../rope/rope.hpp"

#include <iostream>
#include <cstdio>

void get_colorMode();
void get_color_value();
void set_color();

Rope *Rope::instance = 0;

int main() {
	get_color_value();
	set_color();
	get_colorMode();
}








void get_colorMode() {
	Rope *r = r->get_instance();
	std::cout << "r->colorMode(): " << r->colorMode() << std::endl;
	std::cout << r->colorModeX << " | " << r->colorModeX << " | " << r->colorModeX << " | " << r->colorModeX << " | " << std::endl;
	r->colorMode(r->RGB,1);
	std::cout << "r->colorMode(): " << r->colorMode() << std::endl;
	std::cout << r->colorModeX << " | " << r->colorModeX << " | " << r->colorModeX << " | " << r->colorModeX << " | " << std::endl;
}


void set_color() {
	Rope *r = r->get_instance();
	int arg = r->ROUGE;
	r->color(arg);
	float gray = 23.0f;
	r->color(gray);
	float alpha = 34.0;
	r->color(gray, alpha);
	float red = 255.0f;
	float green = 0.0f;
	float blue = 0.0f;
	r->color(red,green,blue);
	r->color(red,green,blue,alpha);
	// by default the colorMode is r.colorMode(r.RGB,255,255,255,255);
	// you can set like you want with only condition it's positive value.
	r->colorMode(r->HSB,360,100,100,100);
	float hue = 0.0f;
	float saturation = 100.0f;
	float brightness = 100.0f;
	r->color(hue,saturation,brightness);
	r->color(hue,saturation,brightness,alpha);
}


void get_color_value() {
	Rope *r = r->get_instance();
  r->colorMode(r->RGB,255);
	r->color(r->AZUR);
	r->colorMode(r->HSB,1);
	std::cout << "r->AZUR: " << r->AZUR  << std::endl;
	std::cout << "r->color():" << r->color() << std::endl;
	std::cout << "r->AZUR split RGB " << r->red() << ", " <<  r->gre() << ", " << r->blu()  << std::endl;
	std::cout << "r->AZUR split HSB " << r->hue() << ", " <<  r->sat() << ", " << r->bri()  << std::endl;
}




