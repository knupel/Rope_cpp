path_test="../test/"
path="../src/"
path_template="../src/template/"
path_class="../src/class/"
path_function="../src/function/"
clang++ -std=c++11 \
${path_test}main_test_utils.cpp \
${path}*.cpp ${path}*.hpp \
${path_template}utils/*.hpp \
&& ./a.out \
&& rm ${path}*.gch ${path_template}utils/*.gch


