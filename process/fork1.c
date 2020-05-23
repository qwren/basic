#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	fork();
	printf("hello\n");
	fork();	
	printf("hello\n");
	while(1);
}
