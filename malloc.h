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
#define CHECK_VALID_MOD 30000

struct s_region;

typedef struct s_block{
	struct s_block *next;
	struct s_block *prev;
	size_t size;
	int free;
	struct s_region *region;
	unsigned int check;
} t_block;

typedef struct s_region{
	struct s_region *next;
	struct s_region *prev;
	size_t size;
	t_block *blocks;
	size_t used;
	int region_type;
	
} t_region;

t_region *regions[3];

void	*malloc(size_t size);
void	show_alloc_mem(void);
void	free(void *ptr);
void	*realloc(void *ptr, size_t size);
int		block_exists(t_block *block);

#endif
