#include "./test_vec.hpp"


void random_test() {
	double d1 = 100.3;
	double d2 = 32.5;
	vec2<float> a(13.03f,1.0f);
	vec3<float> f_3(d1,d2,200);
	vec2<double> e(123,34);


	std::cout << "a: " << a << " type: " << a.get_type() << " random: " << a.rand(0,1) <<std::endl;
	auto start = std::chrono::system_clock::now();

	// SLOW with a lot of instance
	for(int i = 0 ; i < 100000 ; i++) {
		a.rand(0,1);
		// std::cout << a.rand(0,1000) <<std::endl; 
	}
	// FASTER
	std::random_device seed;
	std::default_random_engine generator(seed());
	for(int i = 0 ; i < 100 ; i++) {
		a.rand(0,1,generator);
		// std::cout << a.rand(0,1000,generator) <<std::endl; 
	}

  // time
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << std::endl;

	std::cout << "e: " << e << " type: " << e.get_type() << " random: " << e.rand(-10,10) << std::endl;
	// test time

	std::cout << f_3.set(1,2,3) << std::endl;
	std::cout << f_3.z(8) << std::endl;
	std::cout << f_3.rand(0,1000,generator) <<std::endl; 

}
