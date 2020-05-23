#include <stdio.h>
#include <stdlib.h>

extern void foo(void);
extern void bar(void);

int main(void)
{
    foo();
    bar();
    printf("main\n");

    return 0;
}

