path_test="../test/"
path="../rope/"
path_template="../rope/template/"
path_class="../rope/class/"
path_function="../rope/function/"
clang++ -std=c++11 \
${path}*.hpp \
${path_template}vec/*.hpp \
&& clang++ -std=c++11 \
${path}*.cpp \
${path_function}*.cpp \
${path_test}main_test_constants.cpp \
&& ./a.out \
&& rm ${path}*.gch ${path_template}constants/*.gch ${path}*.pch ${path_template}constants/*.pch