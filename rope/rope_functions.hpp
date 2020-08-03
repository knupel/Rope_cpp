/**
* Rope C++
* v 0.0.4
* 2020-2020
* Rope C++ library adaptation in the same way of Rope from Processing
* Rope mean ROmanesco Processing Environment at the beginning !!!
* https://github.com/StanLepunK/Rope
*/
#ifndef R_FUNCTIONS_H
# define R_FUNCTIONS_H

#pragma once

#include <iostream>
#include <cmath>
#include <random>
// #include <vector>
// #include <limits>
// #include <string>
/**
* math
*/
double dist_on_sphere(double lat_1, double long_1, double lat_2, double lon_2, double radius);


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