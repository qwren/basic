gcc -c foo.c
gcc -c bar.c
gcc -c main.c
gcc main.o foo.o bar.o -o test
