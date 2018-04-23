#ifndef MALLOC_H
# define MALLOC_H

#include "libft/includes/libft.h"
#include <sys/mman.h>
#include <unistd.h>

#define TINY_MAX_SIZE 992
#define SMALL_MAX_SIZE 127000
#define TINY_REGION_PAGES 256
#define SMALL_REGION_PAGES 4096

typedef struct s_block{
	struct s_block *next;
	size_t size;
	int free;
	int region_start;
} t_block;

t_block *block_list[3];

void *malloc(size_t size);
void show_alloc_mem(void);

#endif
