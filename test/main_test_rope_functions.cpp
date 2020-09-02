#include "../rope/template/utils/r_utils.hpp"
#include "../rope/function/rand.hpp"
#include "../rope/function/rand_fast.hpp"

#include "../rope/template/vec/vec4.hpp"

#include <iostream>
#include <cstdio>
#include <limits>

void random_test();
void random_fast_test();

int main() {
	random_test();
	random_fast_test();
}


void random_fast_test() {
	int iter = 10;
	float sum = 0;
			uint32_t seed = random_int(UINT_MAX);
		vec4<uint32_t> seed4;
		seed4.rand(UINT_MAX);
	for(int i = 0 ; i < iter ; i++) {
		std::cout << " random_fast_128(seed): " << random_fast_128(seed4) << std::endl;
		float res = random_fast_128(seed4, -10, 10);
		std::cout << " random_fast_128(seed, -10, 10): " << res << std::endl;
		sum += res;
		std::cout << " random_fast_32(seed): " << random_fast_32(seed) << std::endl;
		std::cout << " random_fast_32(seed, 0, 1000): " << random_fast_32(seed, 0,1000) << std::endl;
		std::cout << " random_fast_64(seed): " << random_fast_64(seed) << std::endl;
		double d_min = std::numeric_limits<double>::lowest();
		double d_max = std::numeric_limits<double>::max();
		float f_min = std::numeric_limits<float>::lowest();
		float f_max = std::numeric_limits<float>::max();
		std::cout << " random_fast_64(seed,f_min,f_max): " << random_fast_64(seed,f_min,f_max) << std::endl;
		std::cout << " random_fast_64(seed,d_min,d_max): " << random_fast_64(seed,d_min,d_max) << std::endl;
		// std::cout << " random_fast_64(seed,-DBL_MAX,DBL_MAX): " << random_fast_64(seed,-DBL_MAX,DBL_MAX) << std::endl;

	}
	std::cout << "average: " << sum / iter << std::endl;


}



void random_test() {
	std::cout << vec4<uint32_t>(32) << std::endl;
	std::cout << " random(0, 10): " << random(0, 10) << std::endl;
	std::cout << " random(0, 10): " << random(0, 10) << std::endl;
	std::random_device seed;
	std::default_random_engine generator(seed());
	std::cout << " random(0, 10, generator): " << random(0, 10, generator) << std::endl;

}