str="./src/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
test/main_test_vec.cpp \
${str}*.cpp ${str}*.hpp \
${str}vec/*.hpp \
${str}math/*.hpp \
&& ./a.out \
&& rm ${str}/*.gch ${str}vec/*.gch ${str}math/*.gch


