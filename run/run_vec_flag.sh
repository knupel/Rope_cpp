path_test="../test/vec/"
path="../rope/"
path_template="../rope/template/"
path_class="../rope/class/"
path_function="../rope/function/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
${path}*.hpp \
${path_template}vec/*.hpp \
&& clang++ -std=c++11 \
${path}*.cpp \
${path_function}*.cpp \
${path_test}*.cpp \
&& ./a.out \
&& rm ${path}*.gch ${path_template}vec/*.gch



