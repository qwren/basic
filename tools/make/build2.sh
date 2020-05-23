[ foo.o -ot foo.c ] && gcc -c foo.c
[ bar.o -ot bar.c ] && gcc -c bar.c
[ main.o -ot main.c ] && gcc -c main.c
[ test -ot main.o ] && [ test -ot foo.o ] && [ test -ot bar.o ] && gcc main.o foo.o bar.o -o test
