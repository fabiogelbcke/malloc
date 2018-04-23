#include "malloc.h"
#include <stdio.h> 

int main(void)
{
	char *test = (char*)malloc(50);
	for (int i = 0; i < 5000; i++)
		test = (char*)malloc(50);
	char *test2 = (char*)malloc(50);
	//show_alloc_mem();
	printf("\n%lu\n", sizeof(t_block));
	return (1);
}
