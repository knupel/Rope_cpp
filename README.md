# ROPE C++
Rope c++ est une collection de fonctions, template et de classe inspirée de la librairie Rope et de Processing.
Contrairement à Rope qui est très lié à Processing, Rope C++ est libre de tout framework et peut-être utilisée seule.
[rope](https://github.com/StanLepunK/Rope) et [Processing](https://github.com/processing/processing)

Rope c++ is a collection of functions, templates and classes inspired by the Rope library and Processing.
Contrary to Rope which is closely related to Processing, Rope C++ is free of any framework and can be used alone.
[rope](https://github.com/StanLepunK/Rope) and [Processing](https://github.com/processing/processing)

# TEST
Tout le code possède une partie test que vous retrouvez dans le dossier `test`, vous pouvez les lancer via les différents que vous trouverez dans le dossier `run` 

sélectionné votre script et `$bash your_script.sh`

All the code has a test part that you can find in the `test` directory, you can run them through the different ones you can find in the `run` directory.

select your script `$bash your_script.sh`

# CONTENT
L'ensemble du code se trouve dans le dossier `rope`si vous souhaitez vous en servir copier coller le dans votre projet et faire vos `include` en respectant le chemin.

All the code is in the `rope` directory if you want to use it, copy and paste it into your project and make your `include` in the path.

## CLASSES
* Rope 
* R_Body

## TEMPLATES
### template vec classes
* vec 
* vec2 
* vec3 
* vec4


### template functions math geometry
* void coord_polar(T &x, T &y, T radius, T dir); 
* vec3<T> coord_sphere_math(T longitude, T latitude, T radius);

### template functions utils
* void set_list(std::vector<V,A> &list, T ... elem);
* T map(T const &arg, T const &start_src, T const &stop_src, T const &start_dst, T const &stop_dst);
* T constrain(T const &arg, T const &min, T const &max);
* T clamp(T const &arg, T const &min, T const &max);
* bool dist_manhattan(T dist, T x, T y ,T z = 0, T w = 0);

### functions
#### functions random
* float random(float min, float max);
* float random(float min, float max, std::default_random_engine &generator);

* double random_double(double min, double max);
* double random_double(double min, double max, std::default_random_engine &generator);

* long double random_long_double(long double min, long double max);
* long double random_long_double(long double min, long double max, std::default_random_engine &generator);

* bool random_bool();
* bool random_bool(std::default_random_engine &generator);

* int random_int(int min, int max);
* int random_int(int min, int max, std::default_random_engine &generator);

* long random_long(long min, long max);
* long random_long(long min, long max, std::default_random_engine &generator);

* char random_char(char min, char max);
* char random_char(char min, char max, std::default_random_engine &generator);

* double random_normal(double min, double max);
* double random_normal(double min, double max, std::default_random_engine &generator);

* int random_geom(double arg);
* int random_geom(double arg, std::default_random_engine &generator);

* double random_exp(double arg);
* double random_exp(double arg, std::default_random_engine &generator);






