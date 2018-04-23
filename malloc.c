#include "malloc.h"

t_block *block_list[3] = {NULL, NULL, NULL};

size_t get_region_size(int region_type, size_t size)
{
	size_t region_size;
	
	if (region_type == 0)
		region_size = TINY_REGION_PAGES * getpagesize();
	else if (region_type == 1)
		region_size = SMALL_REGION_PAGES * getpagesize();
	else
	{
		region_size = size;
		if (region_size % getpagesize() != 0)
			region_size = (region_size % getpagesize()) + getpagesize();
	}
	return region_size;
}

void *allocate_region(int region_type, size_t size)
{
	void *region_space;
	size_t region_size;
	
	region_size = get_region_size(region_type, size);
	region_space = mmap(0, region_size, PROT_READ | PROT_WRITE,
		 MAP_ANON | MAP_PRIVATE, -1, 0);
	block_list[region_type] = region_space;
	return region_space;
}

int has_enough_space(size_t size, int region_type){
	t_block *block;
	
	if (region_type == 2 || !block_list[region_type])
		return (0);
	block = block_list[region_type];
	while (block->next != NULL){
		if (block->free == 1 && block->size >= size + sizeof(t_block))
			return (2);
		block = block->next;
	}
	if (get_region_size(region_type, size) > ((int)block - block->region_start) + block->size + size + (2 * sizeof(t_block)))
		return (1);
	return (0);
}

void *malloc(size_t size)
{
	int region_type;
	t_block *block_info;
	int has_space;


	if (size == 0)
		return NULL;
	region_type = (size <= TINY_MAX_SIZE) ? 0 : 1;
	region_type = (size <= SMALL_MAX_SIZE) ? region_type : 2;
	has_space = has_enough_space(size, region_type);
	
	if (has_space == 0)
	{
		block_info = allocate_region(region_type, size);
		ft_putstr("doesnt have space \n");
		block_info->region_start = (int)block_info;
		if (block_info == (void*) -1)
			return (NULL);
		block_list[region_type] = block_info;
	}
	else if (has_space == 1){
		block_info = block_list[region_type];
		//ft_putstr("has space\n");
		while (block_info->next){
			block_info = block_info->next;
		}
		block_info->next = (void*)block_info + block_info->size + sizeof(t_block);
		block_info->next->region_start = block_info->region_start;
		block_info = block_info->next;
	}
	block_info->size = size;
	block_info->free = 0;
	block_info->next = NULL;
	return (void*)(block_info + 1);
}
