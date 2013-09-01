objects = hello.o
hello : $(objects)
   gcc -o hello $(objects) -L C:/MinGW/lib/gcc/mingw32/4.7.2/ -1stdc++
$(objects): hello.cpp
   gcc -c hello.cpp

all:
   ${MAKE} hello
.PHONY : clean
clean :
   -del hello.exe $ (objects)