path_test="../test/"
path="./rope/"
path_template="./rope/template/"
path_class="./rope/class/"
path_function="./rope/function/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
${path_test}main_test_color.cpp \
${path}*.cpp ${path}*.hpp \
${path_template}utils/*.hpp \
&& ./a.out \
&& rm ${path}*.gch ${path_template}utils/*.gch