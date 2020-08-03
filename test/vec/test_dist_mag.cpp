#include "./header_vec.hpp"

void dist_mag_test() {
	vec2<int> ia(13,1);
	vec2<int> ib(1,3);


	vec2<float> a(13.03f,1.0f);
	vec2<float> b(1.23f,3.14f);
	vec2<float> c(0.0f,0.0f);
	vec2<float> d(2.0f,2.0f);

	vec3<double> a_3(0,1,0);
	vec3<double> b_3(1,1,1);

	std::cout << c << d << std::endl;
	std::cout <<"c.dist(d): " << c.dist(d) << std::endl;
	std::cout << a_3 << b_3 << std::endl;
	std::cout << "a_3.dist(b_3): " << a_3.dist(b_3) << std::endl;
	std::cout << "a_3.mag(): " << a_3.mag() << std::endl;
	std::cout << "b_3.mag(): " << b_3.mag() << std::endl;

	std::cout <<"a.mag(): " << a.mag() << std::endl;
	std::cout <<"a.mag(b): " << a.mag(b) << std::endl;
  
	std::cout <<"a.mag_sq(): " << b.mag_sq() << std::endl;
	std::cout <<"a.mag_sq(b): " << b.mag_sq(a) << std::endl;

	
	int max = 100000000;
	auto start = std::chrono::system_clock::now();
	for(int i = 0 ; i < max ; i++) {
		if(a_3.x() < a_3.y()) { }
	}
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000 << " millions operations of if comparaison" << std::endl;

	start = std::chrono::system_clock::now();
	for(int i = 0 ; i < max ; i++) {
		ia.dist(ib);
	}
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000<< " millions operations of vec2<int> dist()" << std::endl;

		start = std::chrono::system_clock::now();
	for(int i = 0 ; i < max ; i++) {
		a.mag_sq(b);
	}
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000<< " millions operations of vec2<float> mag_sq()" << std::endl;



	start = std::chrono::system_clock::now();
	for(int i = 0 ; i < max ; i++) {
		a.dist(b);
	}
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000<< " millions operations of vec2<float> dist()" << std::endl;

	start = std::chrono::system_clock::now();
	for(int i = 0 ; i < max ; i++) {
		a_3.mag_sq(b_3);
	}
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000<< " millions operations of vec3<double> mag_sq()" << std::endl;

	start = std::chrono::system_clock::now();
	for(int i = 0 ; i < max ; i++) {
		a_3.dist(b_3);
	}
	end = std::chrono::system_clock::now();
	elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " for " << max / 1000000<< " millions operations of vec3<double> dist()" << std::endl;


}