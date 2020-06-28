#include "R_Body.hpp"

int R_Body::instance = 0;
bool R_Body::_warning = false;

R_Body::R_Body() {
	if(R_Body::_warning) {
		std::cout << "R_Body default constructor" << std::endl;
		R_Body::instance++;
	}
	return;
}

R_Body::R_Body(float x, float y, float z) : _x(x), _y(y), _z(z) {
	if(R_Body::_warning) {
		std::cout << "R_Body parametric constructor" << std::endl;
		R_Body::instance++;
	}
	return;
}

R_Body::~R_Body() {
	if(R_Body::_warning) {
		std::cout << "R_Body destructor" << std::endl;
		R_Body::instance--;
	}
	return;
}

// info
int R_Body::get_instance(){
	return R_Body::instance;
}

void R_Body::warning(bool is) {
	R_Body::_warning = is;
}

bool R_Body::warning() {
	return R_Body::_warning;
}

// set
void R_Body::x(float x) {
	this->_x = x;
}

void R_Body::y(float y) {
	this->_y = y;
}

void R_Body::z(float z) {
	this->_z = z;
}

void R_Body::set(float x, float y, float z) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

void R_Body::size(float size) {
	this->_size = size;
}

void R_Body::speed(float speed) {
	this->_speed = speed;
}

void R_Body::dir(float dir) {
	this->_dir = dir;
}


// get
float R_Body::x() const {
	return this->_x;
}

float R_Body::y() const {
	return this->_y;
}

float R_Body::z() const {
	return this->_z;
}

vec3<float> R_Body::pos() const {
	return vec3<float>(this->_x,this->_y,this->_z);
}


float R_Body::size() const {
	return this->_size;
}

float R_Body::dir() const {
	return this->_dir;
}

float R_Body::speed() const {
	return this->_speed;
}








