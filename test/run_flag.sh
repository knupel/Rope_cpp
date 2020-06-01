str="../src/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
main.cpp \
${str}*.cpp \
${str}vec/*.hpp \
${str}math/*.hpp \
&& ./a.out \
&& rm ${str}vec/*.gch ${str}math/*.gch


