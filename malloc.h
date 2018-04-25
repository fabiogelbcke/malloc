#ifndef MALLOC_H
# define MALLOC_H

#include "libft/includes/libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>

#define TINY_MAX_SIZE 992
#define SMALL_MAX_SIZE 127000
#define TINY_REGION_PAGES 256
#define SMALL_REGION_PAGES 4096

typedef struct s_block{
	struct s_block *next;
	size_t size;
	int free;
	t_region *region;
} t_block;

typedef struct s_region{
	struct s_region *next;
	size_t size;
	t_block *blocks;
	long int used;
} t_region;

t_region *regions[3];

void *malloc(size_t size);
void show_alloc_mem(void);

#endif
