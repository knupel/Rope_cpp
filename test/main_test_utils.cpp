#include "../rope/template/utils/r_utils.hpp"
#include "../rope/rope_functions.hpp"
#include "../rope/template/vec/vec4.hpp"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <chrono>
#include <ctime>
#include <limits>

/**
* bool dist_manhathan()
* v 0.0.1
* 2020-2020
* return if an element is in the range 5 once faster 
* with 10% range of error for the draw 
* and 5% for the error distance
* Note : more there is dimension vor your vector, less there is error.
* inspired fom this article
* https://en.wikipedia.org/wiki/Taxicab_geometry
* https://stackoverflow.com/questions/3693514/very-fast-3d-distance-check
*/
template <typename T>
bool dist_manhattan_is(T dist, T x, T y ,T z = 0, T w = 0) {
	if(x + x > dist)
		return false;
	if(y + y > dist)
		return false;
	if(z + z > dist)
		return false;
	if(w + w > dist)
		return false;
	return true; 	
}

template <typename T>
T dist_manhattan(T x, T y ,T z = 0, T w = 0) {
	return abs(x) + abs(y) + abs(z) + abs(w);
}

void compare_dist_manhattan(int max, int size);
void compare_dist_manhattan_is_speed(int max);
void compare_dist_manhattan_is_diff_2d(int max, int size);
void compare_dist_manhattan_is_diff_3d(int max, int size);
void compare_dist_manhattan_is_diff_4d(int max, int size);
void log_diff_manhattan(int max, int inf, int sup, int man_inf, int man_sup, float diff_total, float dist_total);


void constrain_clamp_test();
void random_test();



int main(int argc, const char * argv[]) {
	int max = atoi(argv[1]);
	int size = atoi(argv[2]);
	// compare_dist_manhattan(max, size);
	// compare_dist_manhattan_diff_2d(max, size);
	// compare_dist_manhattan_diff_3d(max, size);
	// compare_dist_manhattan_diff_4d(max, size);
	compare_dist_manhattan_is_speed(max);
	// constrain_clamp_test();
	// random_test();
}

void compare_dist_manhattan_is_diff_2d(int max, int size) {
	std::cout << "\nvoid compare_dist_manhattan_is_diff_2d(int max, int size)" << std::endl;
	vec2<float> a;
	float dist = size;
	int inf = 0;
	int sup = 0;
	int man_inf = 0;
	int man_sup = 0;
	float diff_total = 0;
	float dist_total = 0;

	for(int i = 0 ; i < max ; i++) {
		a.rand(-1,1);
		a *= size;
		bool dist_is;
		float dist_vec = a.dist();
		dist_vec < dist ? dist_is = true : dist_is = false;
		if(dist_is) {
			inf++;
		} else {
			sup++;
		}
		bool dist_manhathan_is = dist_manhattan_is<float>(dist, a.x(), a.y());
		if(dist_manhathan_is) {
			man_inf++;
		} else {
			man_sup++;
		}
    // add the diff is there is a difference between manhatan method and the real dist();
		if(dist_is != dist_manhathan_is) {
			diff_total += abs(dist_vec - dist);
		}
		dist_total += dist;
	}
	log_diff_manhattan(max, inf, sup, man_inf, man_sup, diff_total, dist_total);
}



void compare_dist_manhattan_is_diff_3d(int max, int size) {
	std::cout << "\nvoid compare_dist_manhattan_is_diff_3d(int max, int size)" << std::endl;
	vec3<float> a;
	float dist = size;
	int inf = 0;
	int sup = 0;
	int man_inf = 0;
	int man_sup = 0;
	float diff_total = 0;
	float dist_total = 0;

	for(int i = 0 ; i < max ; i++) {
		a.rand(-1,1);
		a *= size;
		bool dist_is;
		float dist_vec = a.dist();
		dist_vec < dist ? dist_is = true : dist_is = false;
		if(dist_is) {
			inf++;
		} else {
			sup++;
		}
		bool dist_manhathan_is = dist_manhattan_is<float>(dist, a.x(), a.y(), a.z());
		if(dist_manhathan_is) {
			man_inf++;
		} else {
			man_sup++;
		}
    // add the diff is there is a difference between manhatan method and the real dist();
		if(dist_is != dist_manhathan_is) {
			diff_total += abs(dist_vec - dist);
		}
		dist_total += dist;
	}
	log_diff_manhattan(max, inf, sup, man_inf, man_sup, diff_total, dist_total);
}

void compare_dist_manhattan_is_diff_4d(int max, int size) {
	std::cout << "\nvoid compare_dist_manhattan_is_diff_4d(int max, int size)" << std::endl;
	vec4<float> a;
	float dist = size;
	int inf = 0;
	int sup = 0;
	int man_inf = 0;
	int man_sup = 0;
	float diff_total = 0;
	float dist_total = 0;

	for(int i = 0 ; i < max ; i++) {
		a.rand(-1,1);
		a *= size;
		bool dist_is;
		float dist_vec = a.dist();
		dist_vec < dist ? dist_is = true : dist_is = false;
		if(dist_is) {
			inf++;
		} else {
			sup++;
		}
		bool dist_manhathan_is = dist_manhattan_is<float>(dist, a.x(), a.y(), a.z(), a.w());
		if(dist_manhathan_is) {
			man_inf++;
		} else {
			man_sup++;
		}
    // add the diff is there is a difference between manhatan method and the real dist();
		if(dist_is != dist_manhathan_is) {
			diff_total += abs(dist_vec - dist);
		}
		dist_total += dist;
	}
	log_diff_manhattan(max, inf, sup, man_inf, man_sup, diff_total, dist_total);
}

void log_diff_manhattan(int max, int inf, int sup, int man_inf, int man_sup, float diff_total, float dist_total) {
	std::cout << inf << " | " << sup << " classic" << std::endl;
	std::cout << man_inf << " | " << man_sup << " manhathan" << std::endl;
	std::cout << "draw sup dif " << sup - man_sup << " / " << max << std::endl;
	std::cout << "draw inf dif " << inf - man_inf << " / " << max << std::endl;
	std::cout << "dist dif " << diff_total << " / " << dist_total << std::endl;
}


void compare_dist_manhattan_is_speed(int max) {
	std::cout << "\nvoid compare_dist_manhattan_is_speed(int max)" << std::endl;
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
  	dist_manhattan_is<float>(1,a.x(), a.y(), a.z());
  }
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000 << " M to calcule dist_manhatan()" << std::endl;
}

void compare_dist_manhattan(int max, int size) {
	std::cout << "\nvoid compare_dist_manhattan(int max)" << std::endl;
	vec2<float> a2;
  for(int i = 0 ; i < max ; i++) {
  	a2.rand(-1,1);
  	a2 * size;
  	std::cout << a2.dist() << "a2.dist(): "  << std::endl;
  	std::cout << dist_manhattan(a2.x(), a2.y()) << "dist_manhattan(a2.x(), a2.y(): "  << std::endl;
  }
	vec3<float> a3;
  for(int i = 0 ; i < max ; i++) {
  	a3.rand(-1,1);
  	a3 * size;
  	std::cout << a3.dist() << "a3.dist(): " <<  std::endl;
  	std::cout << dist_manhattan(a3.x(), a3.y(), a3.z()) << "dist_manhattan(a3.x(), a3.y(), a3.z()): " <<  std::endl;
  }
  vec4<float> a4;
  for(int i = 0 ; i < max ; i++) {
  	a4.rand(-1,1);
  	a4 * size;
  	std::cout << a4.dist() << "a4.dist(): " <<  std::endl;
  	std::cout << dist_manhattan(a4.x(), a4.y(), a4.z(), a4.w()) << "dist_manhattan(a4.x(), a4.y(), a4.z(), a4.w()): " <<  std::endl;
  }
}







void constrain_clamp_test() {
	std::cout << "\nvoid constrain_clamp_test()" << std::endl;
	float a = random(-10,10);
	std::cout << "constrain(" << a << ",-5,5): " << constrain<float>(a,-5,5) << std::endl;
	std::cout << "clamp(" << a << ",-5,5): " << clamp<float>(a,-5,5) << std::endl;
	a = -100;
	std::cout << "a: " << a << std::endl;
	constrain<float>(a,-5,5);
	std::cout << "a = constrain(" << a << ",-5,5): " << a << std::endl;
	double b = random_double(-10,10);
	std::cout << "constrain(" << b << ",-5,5): " << constrain<double>(b,-5,5) << std::endl;
	std::cout << "clamp(" << b << ",-5,5): " << clamp<double>(b,-5,5) << std::endl;
	int i = random_int(-10,10);
	std::cout << "constrain(" << i << ",-5,5): " << constrain<int>(i,-5,5) << std::endl;
	std::cout << "clamp(" << i << ",-5,5): " << clamp<int>(i,-5,5) << std::endl;	
}

void random_test() {
	std::cout << "\nvoid random_test()" << std::endl;
	std::cout << "random_double(-10,10): " << random_double(-10,10) << std::endl;
	std::cout << "random_int(-10,10): " << random_int(-10,10) << std::endl;
	std::cout << "random_bool(): " << random_bool() << std::endl;

	std::random_device seed;
	std::default_random_engine generator(seed());
  
  long double ld_min = std::numeric_limits<long double>::min();
  long double ld_max = std::numeric_limits<long double>::max();
	std::cout << "random_long_double(ld_min, ld_max, generator): " << random_long_double(ld_min, ld_max, generator) << std::endl;
}