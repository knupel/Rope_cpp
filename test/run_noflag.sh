str="../src/" \
# echo $str \
clang++ -std=c++11 \
main.cpp ${str}*.hpp \
${str}*.cpp ${str}*.hpp \
${str}vec/*.hpp \
${str}math/*.hpp \
&& ./a.out \
&& rm ${str}*.gch ${str}vec/*.gch ${str}math/*.gch 