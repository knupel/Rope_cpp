/**
* ROPE FUNCTIONS
* v 0.1.0
* 2020-2020
*/
#include "./rand_fast.hpp"


/**
* RANDOM FAST
*/
/**
* random fast
* https://en.wikipedia.org/wiki/Xorshift
*/
uint32_t random_fast_128(vec4<uint32_t> &seed) {
	static uint32_t x = seed.x();
	static uint32_t y = seed.y();
	static uint32_t z = seed.z();
	static uint32_t w = seed.w();
	uint32_t t;
	t = x ^ (x << 11);   
	x = y; 
	y = z; 
	z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

uint64_t random_fast_64(uint32_t seed) {
	uint64_t x = seed;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return x;
}


uint32_t random_fast_32(uint32_t seed) {
	uint32_t x = seed;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x;
}


