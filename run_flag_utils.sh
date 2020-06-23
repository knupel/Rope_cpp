str="./src/"
clang++ -std=c++11 \
-Wall -Wextra -Werror -Wconversion \
test/main_test_utils.cpp \
${str}*.cpp ${str}*.hpp \
${str}vec/*.hpp \
${str}math/*.hpp \
${str}utils/*.hpp \
&& ./a.out \
&& rm ${str}*.gch ${str}vec/*.gch ${str}math/*.gch ${str}utils/*.gch


