#include "malloc.h"
#include <stdio.h> 

int main(void)
{
	char *test = (char*)malloc(50);
	char *test2 = (char*)malloc(60);
	char *test3 = (char*)malloc(70);
	char *test4 = (char*)malloc(80);
	char *test5 = (char*)malloc(90);
	char *test6 = (char*)malloc(100);
	free(test3);
	realloc(test2, 180);
	show_alloc_mem();
	return (1);
}
