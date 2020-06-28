/**
* R_BODY
* v 0.1.0
* 2020-2020
*/
#ifndef R_BODY_H
# define R_BODY_H
#pragma once

#include <iostream>
#include "../template/vec/vec3.hpp"

class R_Body {
	public:
		R_Body();
		R_Body(float x, float y, float z);
		~R_Body();

		// info
		static int get_instance();
		static void warning(bool is);
		static bool warning();
		
		// get
		float x() const;
		float y() const;
		float z() const;
		vec3<float> pos() const;

		float size() const;

		float dir() const;
		float speed() const;

		// set
		void x(float x);
		void y(float y);
		void z(float z);
		void set(float x, float y, float z = 0);

		void size(float size);

		void dir(float dir);
		void speed(float speed);	

	protected:
		static int instance;
		static bool _warning;

	private:
		float _x;
		float _y;
		float _z;

		float _size = 1.0f;

		float _dir = 0.0f;

		float _speed = 0.0f;
}; 

#endif