#include <stdio.h>
#include <stdlib.h>
#include "foo.h"
#include "bar.h"

int main(void)
{
    foo();
    bar();
    printf("main\n");

    return 0;
}

