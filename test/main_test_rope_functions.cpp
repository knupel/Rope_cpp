#include "../rope/template/utils/r_utils.hpp"
#include "../rope/function/rand.hpp"
#include "../rope/function/rand_fast.hpp"

#include "../rope/template/vec/vec4.hpp"

#include <iostream>
#include <cstdio>

void random_test();
void random_fast_test();

int main() {
	random_test();
	random_fast_test();
}


void random_fast_test() {
	uint32_t seed = random_int(UINT_MAX);
	// 	uint32_t x = random_int(UINT_MAX);
	// uint32_t y = random_int(UINT_MAX);
	// uint32_t z = random_int(UINT_MAX);
	// uint32_t w = random_int(UINT_MAX);
	// vec4<uint32_t> seed4(x,y,z,w);
	vec4<uint32_t> seed4;
	seed4.rand(UINT_MAX);
	// seed4.rand(12);
	std::cout << "seed4: " << seed4 << std::endl; 
	std::cout << " random_fast_128(seed): " << random_fast_128(seed4) << std::endl;
	std::cout << " random_fast_64(seed): " << random_fast_64(seed) << std::endl;
	std::cout << " random_fast_32(seed): " << random_fast_32(seed) << std::endl;
}



void random_test() {
	std::cout << vec4<uint32_t>(32) << std::endl;
	std::cout << " random(0, 10): " << random(0, 10) << std::endl;
	std::cout << " random(0, 10): " << random(0, 10) << std::endl;
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::cout << " random(0, 10, generator): " << random(0, 10, generator) << std::endl;

}