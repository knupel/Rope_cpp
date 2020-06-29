#include "../rope/rope.hpp"
#include "../rope/template/vec/vec3.hpp"
#include "../rope/template/utils/r_utils.hpp"

#include <iostream>
#include <cstdio>
#include <chrono>
#include <ctime>

// bool dist_manhathan(float dist, vec3<float> &v);
void compare_speed(int max);
void compare_diff(int max);

int main(int argc, const char * argv[]) {
	vec3<float> b(1);
	
  int max = atoi(argv[1]);
  // compare_diff(max);
	compare_speed(max);
}

void compare_diff(int max) {
	vec3<float> a;
	float dist = 10;
	int inf = 0;
	int sup = 0;
	int man_inf = 0;
	int man_sup = 0;

	for(int i = 0 ; i < max ; i++) {
		a.rand(-1,1);
		a *= 10;
		float a_dist = a.dist();
		if(a_dist < dist) {
			inf++;
		} else {
			sup++;
		}
		if(dist_manhathan<float>(dist, a.x(), a.y(), a.z())) {
		// if(dist_manhathan<float>(dist, a)) {
			man_inf++;
		} else {
			man_sup++;
		}
	}
	std::cout << inf << " | " << sup << " classic" << std::endl;
	std::cout << man_inf << " | " << man_sup << " manhathan" << std::endl;
	std::cout << "dif " << inf - man_inf << " / " << max << std::endl;
}


void compare_speed(int max) {
	vec3<float> a;
	a.rand(-1,1);
  auto start = std::chrono::system_clock::now();
  for(int i = 0 ; i < max ; i++) {
  	// a.rand(-1,1);
  	a.dist();
  }
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000 << " M to calcule vec.dist()" << std::endl;

	start = std::chrono::system_clock::now();
  for(int i = 0 ; i < max ; i++) {
  	//a.rand(-1,1);
  	dist_manhathan<float>(1,a);
  	// dist_manhathan<float>(1,a.x(), a.y(), a.z());
  }
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000 << " M to calcule dist_manhatan()" << std::endl;

}





