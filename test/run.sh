clang++ -std=c++11 \
main.cpp *../src/hpp \
-Wall -Wextra -Werror -Wconversion \
rope/*.cpp rope/*.hpp \
rope/vec/*.hpp \
&& ./a.out \
&& rm rope/*.gch rope/vec/*.gch 