path_test="../test/"
path="../rope/"
path_template="../rope/template/"
path_class="../rope/class/"
path_function="../rope/function/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
clang++ -std=c++11 \
${path_test}main_test_vec.cpp \
${path}*.cpp ${path}*.hpp \
${path_template}vec/*.hpp \
&& ./a.out \
&& rm ${path}/*.gch ${path_template}vec/*.gch


