CC=gcc -Wall -c
LD=gcc

foo.o: foo.c
#	gcc -Wall -c foo.c -o foo.o
	$(CC) foo.c -o foo.o
bar.o: bar.c
#	gcc -Wall -c bar.c -o bar.o
	$(CC) bar.c -o bar.o
main.o: main.c
#	gcc -Wall -c main.c -o main.o
	$(CC) main.c -o main.o
test: foo.o bar.o main.o
#	gcc main.o foo.o bar.o -o test 
	$(LD) main.o foo.o bar.o -o test
