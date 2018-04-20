#ifndef MALLOC_H
# define MALLOC_H

#define TINY_MAX_SIZE 992
#define SMALL_MAX_SIZE 127000
#define TINY_REGION_PAGES 256
#define SMALL_REGION_PAGES 4096

typedef struct s_block{
	t_block *next;
	size_t size;
	int pos;
	int free;
	int region_start;
} t_block;

t_block *block_list[3] = {NULL, NULL, NULL};

#endif
