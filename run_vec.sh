str="./src/"
clang++ -std=c++11 \
test/main_test_vec.cpp \
${str}*.cpp ${str}*.hpp \
${str}vec/*.hpp \
${str}math/*.hpp \
&& ./a.out \
&& rm ${str}/*.gch ${str}vec/*.gch ${str}math/*.gch


