path_test="../test/"
path="../rope/"
path_template="../rope/template/"
clang++ -std=c++11 \
${path}*.hpp \
${path}function/*.hpp \
${path_template}utils/*.hpp \
${path_template}vec/*.hpp \
&& clang++ -std=c++11 \
${path_test}main.cpp \
${path}function/*.cpp \
${path}*.cpp \
&& ./a.out 100 10 \
&& rm ${path}*.gch ${path_template}utils/*.gch