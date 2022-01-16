path_test="../test/"
path="../rope/"
path_template="../rope/template/"
path_class="../rope/class/"
path_function="../rope/function/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
${path}*.hpp \
${path_template}utils/*.hpp \
&& clang++ -std=c++11 \
${path_test}main_test_utils.cpp \
${path}*.cpp \
${path_function}*.cpp \
&& ./a.out 100 100 \
&& rm ${path}*.gch ${path_template}utils/*.gch

