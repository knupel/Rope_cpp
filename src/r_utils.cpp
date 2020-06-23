#include "rope.hpp"
/**
* rope utils
* v 0.0.2
* 2020-2020
*/

/**
* Rope
*/





/**
* colour 
* adaptation from Processing
* v 0.0.1
*/

// color
int Rope::color(float gray) {
	colorCalc(gray);
	return calcColor;
}


int Rope::color(int c, float alpha) {
	colorCalc(c, alpha);
	return calcColor;
}

int Rope::color(float gray, float alpha) {
	colorCalc(gray, alpha);
	return calcColor;
}

int Rope::color(float v1, float v2, float v3) {
	colorCalc(v1, v2, v3);
	return calcColor;
}

int Rope::color(float v1, float v2, float v3, float a) {
	colorCalc(v1, v2, v3, a);
	return calcColor;
}


// colocCalc
void Rope::colorCalc(int &rgb) {
	if (((rgb & 0xff000000) == 0) && (rgb <= colorModeX)) {
		colorCalc(rgb);
	} else {
		colorCalcARGB(rgb, colorModeA);
	}
}


void Rope::colorCalc(int &rgb, float &alpha) {
	if (((rgb & 0xff000000) == 0) && (rgb <= colorModeX)) {  // see above
		colorCalc(rgb, alpha);

	} else {
		colorCalcARGB(rgb, alpha);
	}
}
	
void Rope::colorCalc(float &gray) {
	colorCalc(gray, colorModeA);
}

void Rope::colorCalc(float &gray, float &alpha) {
	if (gray > colorModeX)
		gray = colorModeX;
	if (alpha > colorModeA)
		alpha = colorModeA;

	if (gray < 0)
		gray = 0;
	if (alpha < 0)
		alpha = 0;

	calcR = colorModeScale ? (gray / colorModeX) : gray;
	calcG = calcR;
	calcB = calcR;
	calcA = colorModeScale ? (alpha / colorModeA) : alpha;

	/**
	* PROBLEMEEEEEEE
	*
	*
	*
	*
	*/
	std::cout << "rgba: " << calcR << calcG << calcB << calcA << std::endl;

	calcRi = (int)(calcR * 255.0f); 
	calcGi = (int)(calcG * 255.0f);
	calcBi = (int)(calcB * 255.0f); 
	calcAi = (int)(calcA * 255.0f);
	calcColor = (calcAi << 24) | (calcRi << 16) | (calcGi << 8) | calcBi;
	calcAlpha = (calcAi != 255);
}
	
void Rope::colorCalc(float &x, float &y, float &z) {
	colorCalc(x, y, z, colorModeA);
}

void Rope::colorCalc(float &x, float &y, float &z, float &a) {
	if (x > colorModeX) x = colorModeX;
	if (y > colorModeY) y = colorModeY;
	if (z > colorModeZ) z = colorModeZ;
	if (a > colorModeA) a = colorModeA;

	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (z < 0) z = 0;
	if (a < 0) a = 0;

	switch (colorMode) {
	case RGB:
		if (colorModeScale) {
			calcR = x / colorModeX;
			calcG = y / colorModeY;
			calcB = z / colorModeZ;
			calcA = a / colorModeA;
		} else {
			calcR = x; calcG = y; calcB = z; calcA = a;
		}
		break;

	case HSB:
		x /= colorModeX; // h
		y /= colorModeY; // s
		z /= colorModeZ; // b

		calcA = colorModeScale ? (a/colorModeA) : a;

		if (y == 0) {  // saturation == 0
			calcR = calcG = calcB = z;
		} else {
			float which = (x - (int)x) * 6.0f;
			float f = which - (int)which;
			float p = z * (1.0f - y);
			float q = z * (1.0f - y * f);
			float t = z * (1.0f - (y * (1.0f - f)));

			switch ((int)which) {
			case 0: calcR = z; calcG = t; calcB = p; break;
			case 1: calcR = q; calcG = z; calcB = p; break;
			case 2: calcR = p; calcG = z; calcB = t; break;
			case 3: calcR = p; calcG = q; calcB = z; break;
			case 4: calcR = t; calcG = p; calcB = z; break;
			case 5: calcR = z; calcG = p; calcB = q; break;
			}
		}
		break;
	}
	calcRi = (int)(255 * calcR); 
	calcGi = (int)(255 * calcG);
	calcBi = (int)(255 * calcB); 
	calcAi = (int)(255 * calcA);
	calcColor = (calcAi << 24) | (calcRi << 16) | (calcGi << 8) | calcBi;
	calcAlpha = (calcAi != 255);
}

	
void Rope::colorCalcARGB(int &argb, float &alpha) {
	if (alpha == colorModeA) {
		calcAi = (argb >> 24) & 0xff;
		calcColor = argb;
	} else {
		calcAi = (int) (((argb >> 24) & 0xff) * constrain((alpha / colorModeA), 0.0f, 1.0f));
		calcColor = (calcAi << 24) | (argb & 0xFFFFFF);
	}
}


float Rope::red() const {
	return calcR;
}

float Rope::gre() const {
	return calcG;
}

float Rope::blu() const {
	return calcB;
}

float Rope::alp() const {
	return calcA;
}



/**
* Random function to compute few sort or random result.
* v 0.0.4
* http://www.cplusplus.com/reference/random/uniform_real_distribution/
*/
// rand float
float random(float min, float max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random(min, max, generator);
}

float random(float min, float max, std::default_random_engine &generator) {
	std::uniform_real_distribution<float> gen_rand_float(min,max);
	return gen_rand_float(generator); 
}

// rand double
double random_double(double min, double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_double(min,max,generator);
}

double random_double(double min, double max, std::default_random_engine &generator) {
	std::uniform_real_distribution<double> gen_rand_double(min,max);
	return gen_rand_double(generator); 
}

//rand long double
long double random_long_double(long double min, long double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_long_double(min,max,generator);
}

long double random_long_double(long double min, long double max, std::default_random_engine &generator) {
	std::uniform_real_distribution<long double> gen_rand_long_double(min,max);
	return gen_rand_long_double(generator); 
}


// rand bool
bool random_bool() {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_bool(generator);
}

bool random_bool(std::default_random_engine &generator) {
	std::uniform_int_distribution<int> gen_rand_int(0,1);
	return gen_rand_int(generator); 
}

// rand char
char random_char(char min, char max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_char(min,max,generator);
}

char random_char(char min, char max, std::default_random_engine &generator) {
	std::uniform_int_distribution<char> gen_rand_int(min,max);
	return (gen_rand_int(generator));
}

// rand int
int random_int(int min, int max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_int(min,max,generator);
}

int random_int(int min, int max, std::default_random_engine &generator) {
	std::uniform_int_distribution<int> gen_rand_int(min,max);
	return gen_rand_int(generator); 
}

// random long
long random_long(long min, long max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_long(min,max,generator);
}

long random_long(long min, long max, std::default_random_engine &generator) {
	std::uniform_int_distribution<long> gen_rand_int(min,max);
	return gen_rand_int(generator); 
}


// rand normal
double random_normal(double min, double max) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_normal(min,max,generator);
}

double random_normal(double min, double max, std::default_random_engine &generator) {
	std::normal_distribution<double> gen_rand_double(min,max);
	return gen_rand_double(generator); 
}

// rand geom
int random_geom(double arg) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_geom(arg,generator);
}

int random_geom(double arg, std::default_random_engine &generator) {
	std::geometric_distribution<int> gen_rand_int(std::abs(arg));
	return gen_rand_int(generator); 
}

double random_exp(double arg) {
	std::random_device seed;
	std::default_random_engine generator(seed());
	return random_exp(arg,generator);
}

double random_exp(double arg, std::default_random_engine &generator) {
	std::exponential_distribution<double> gen_rand_double(std::abs(arg));
	return gen_rand_double(generator); 
}







