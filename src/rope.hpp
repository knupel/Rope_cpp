/**
* Rope C++
* v 0.0.4
* 2020-2020
* Rope C++ library adaptation in the same way of Rope from Processing
* Rope mean ROmanesco Processing Environment at the beginning !!!
* https://github.com/StanLepunK/Rope
*/
#ifndef ROPE_H
# define ROPE_H

#pragma once

#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <limits>
#include <string>

#include "./utils/r_utils.hpp"
// class Rope
class Rope {
public:
	Rope() {}
	~Rope() {}

	enum Constants {
		RGB = 1,
		HSB = 3
  };

	bool colorModeScale; // = true;
	float colorModeA = 255.0f;
	float colorModeX = 255.0f;
	float colorModeY = 255.0f;
	float colorModeZ = 255.0f;
	int colorMode = 1;



	// color
	int color(float gray);
	int color(int c, float alpha);
	int color(float gray, float alpha);
	int color(float v1, float v2, float v3);
	int color(float v1, float v2, float v3, float a);

	float red() const;
	float gre() const;
	float blu() const;
	float alp() const;


	// color calc
protected:
	bool calcAlpha = true;

	int calcColor = 0;
	int calcAi = 0;
	int calcRi = 0;
	int calcGi = 0;
	int calcBi = 0;

	float calcA = 0;
	float calcR = 0;
	float calcG = 0;
	float calcB = 0;

	void colorCalc(int &rgb);
	void colorCalc(int &rgb, float &alpha);
	void colorCalc(float &gray);
	void colorCalc(float &gray, float &alpha);
	void colorCalc(float &x, float &y, float &z);
	void colorCalc(float &x, float &y, float &z, float &a);

	// color calc ARGB
	void colorCalcARGB(int &argb, float &alpha);
};













// random declaration
float random(float min, float max);
float random(float min, float max, std::default_random_engine &generator);

double random_double(double min, double max);
double random_double(double min, double max, std::default_random_engine &generator);

long double random_long_double(long double min, long double max);
long double random_long_double(long double min, long double max, std::default_random_engine &generator);

bool random_bool();
bool random_bool(std::default_random_engine &generator);

int random_int(int min, int max);
int random_int(int min, int max, std::default_random_engine &generator);

long random_long(long min, long max);
long random_long(long min, long max, std::default_random_engine &generator);

char random_char(char min, char max);
char random_char(char min, char max, std::default_random_engine &generator);

double random_normal(double min, double max);
double random_normal(double min, double max, std::default_random_engine &generator);

int random_geom(double arg);
int random_geom(double arg, std::default_random_engine &generator);

double random_exp(double arg);
double random_exp(double arg, std::default_random_engine &generator);

#endif