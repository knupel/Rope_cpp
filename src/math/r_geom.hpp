/**
* header
* Rope math geom C++
* v 0.0.2
* 2020-2020
* Rope C++ library adaptation in the same way of Rope from Processing
* Rope mean ROmanesco Processing Environment at the beginning !!!
* https://github.com/StanLepunK/Rope
*/

#ifndef R_GEOM_H
# define R_GEOM_H


#pragma once

#include <iostream>
#include <cmath>
#include "../vec/vec3.hpp"

template<typename T>
void coord_polar(T &x, T &y, T radius, T dir) {
	x = sin(dir) * radius;
	y = cos(dir) * radius;

}

template<typename T>
vec3<T> coord_sphere_math(T longitude, T latitude, T radius) {
	double tau = 2.0 *M_PI;
	double theta = fmod(longitude,tau);
	double phi = fmod(latitude,tau);

	T x = static_cast<T>(radius *sin(theta) *cos(phi));
	T y = static_cast<T>(radius *sin(theta) *sin(phi));
	T z = static_cast<T>(radius *cos(theta));

	return vec3<T>(x,y,z);
}

#endif
