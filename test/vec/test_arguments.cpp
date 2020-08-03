#include "./header_vec.hpp"


void arguments_test() {
	vec2<float> a(1,2);
	std::cout << a.x() << a.y() << std::endl;
	std::cout << a.lat() << a.lon() << std::endl;
	std::cout << a.min() << a.max() << std::endl;

	vec3<float> b(1,2,3);
	std::cout << b.x() << b.y() << b.z() << std::endl;
	std::cout << b.red() << b.gre() << b.blu() << std::endl;
	std::cout << b.lat() << b.lon() << b.alt() << std::endl;
	std::cout << b.min() << b.max() << std::endl;

	vec4<float> c(4,3,2,1);
	std::cout << c.x() << c.y() << c.z() << c.w() << std::endl;
	std::cout << c.red() << c.gre() << c.blu() << c.alp() << std::endl;
	std::cout << c.lat() << c.lon() << c.alt() << std::endl;
	std::cout << c.min() << c.max() << std::endl;
	std::cout << c.xxxx() << std::endl;
	std::cout << c.yyyy() << std::endl;
	std::cout << c.zzzz() << std::endl;
	std::cout << c.wwww() << std::endl;
	std::cout << c.wzyx() << std::endl;
}