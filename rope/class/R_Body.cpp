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

void R_Body::set(vec2<float> pos) {
	this->_x = pos.x();
	this->_y = pos.y();
}

void R_Body::set(vec3<float> pos) {
	this->_x = pos.x();
	this->_y = pos.y();
	this->_z = pos.z();
}


void R_Body::translate(float x, float y, float z) {
	this->_x += x;
	this->_y += y;
	this->_z += z;
}

void R_Body::translate(vec2<float> pos) {
	this->_x += pos.x();
	this->_y += pos.y();
}

void R_Body::translate(vec3<float> pos) {
	this->_x += pos.x();
	this->_y += pos.y();
	this->_z += pos.z();
}

bool R_Body::follow(float x, float y, float z) {
	vec3<float> dst(x,y,z);
	float dist = this->pos().dist(dst);
	if(_speed < dist) {
		vec3<float> translate = dst.dir(this->pos()) * _speed;
		this->translate(translate);
		return true;
	}
	return false;
}

bool R_Body::follow(vec2<float> dst) {
	return this->follow(dst.x(), dst.y());
}

bool R_Body::follow(vec3<float> dst) {
	return this->follow(dst.x(), dst.y(), dst.z());
}


bool R_Body::follow_sphere(float lat, float lon, float alt) {
	vec2<float> dst(lat,lon);
	float dist = dist_sphere(this->pos(), dst, alt);
	std::cout << "_speed << dist: " << _speed << " | " << dist << std::endl;
	if(_speed < dist) {
		vec2<float> translate = dst.dir(this->pos().xy()) * _speed;
		this->translate(translate);
		return true;
	}
	std::cout << "C'est faux et archi faux" << std::endl;
	return false;
}

bool R_Body::follow_sphere(vec2<float> dst, float alt) {
	return this->follow_sphere(dst.lat(), dst.lon(), alt);
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









