path_test="../test/main_test_body.cpp"
path="../rope/"
path_template="../rope/template/"
path_class="../rope/class/"
path_function="../rope/function/"
clang++ -std=c++11 \
${path_test} \
${path}*.cpp ${path}*.hpp \
${path_template}utils/*.hpp \
${path_class}R_Body.hpp ${path_class}R_Body.cpp \
&& ./a.out \
&& rm ${path}*.gch ${path_template}utils/*.gch ${path_class}*.gch