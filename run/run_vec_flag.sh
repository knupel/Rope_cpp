path_test="../test/vec/"
path="../rope/"
path_template="../rope/template/"
path_class="../rope/class/"
path_function="../rope/function/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
${path_test}*.cpp \
${path}*.cpp ${path}*.hpp \
${path_template}vec/*.hpp \
&& ./a.out \
&& rm ${path}*.gch ${path_template}vec/*.gch



