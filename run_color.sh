str="./src/"
clang++ -std=c++11 \
test/main_test_color.cpp \
${str}*.cpp ${str}*.hpp \
${str}utils/*.hpp \
&& ./a.out \
&& rm ${str}*.gch ${str}utils/*.gch