#include "malloc.h"

void *allocate_region(int region, size_t size)
{
	void *region_space;
	size_t region_size;
	
	if (region == 1)
		region_size = TINY_REGION_PAGES * getpagesize();
	else if (region == 2)
		region_size = SMALL_REGION_PAGES * getpagesize();
	else
	{
		region_size = size;
		if (region_size % getpagesize() != 0)
			region_size = (region_size % getpagesize()) + getpagesize();
	}
	region_space = mmap(0, region_size, PROT_READ | PROT_WRITE,
		 MAP_ANON | MAP_PRIVATE, -1, 0);
	block_list[region] = region_space;
	return region_space;
}

void *malloc(size_t size)
{
	int region_type;
	
	if (size == 0)
		return NULL;
	region_type = (size <= TINY_MAX_SIZE) ? 0 : 1;
	region_type = (size <= SMALL_MAX_SIZE) ? region_type : 2;
	if (!block_list[region])
		allocate_region(region, size);
	if (block_list[region] == (void*)-1)
		return (block_list
	
}
