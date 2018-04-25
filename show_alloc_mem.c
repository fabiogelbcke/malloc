#include "malloc.h"


char *ft_itox(long int n)
{
	int size;
	char *hex;
	int i;
	long int cpy;

	size = 1;
	i = 1;
	cpy = n;
	while (cpy / 16 > 0)
    {
		size++;
		cpy = cpy / 16;
    }
	hex = (char *)malloc(sizeof(char) * (size + 1));
	hex[size--] = '\0';
	while (n / 16 > 0)
    {
		hex[size--] = 48 + (n - 16 * (n / 16));
		if ((n - 16 * (n / 16)) > 9)
			hex[size + 1] += 39;
		n = n / 16;
    }
	hex[size] = (n <= 9) ? 48 + n : 87 + n;
	return hex;
}

void ft_puthex(size_t n){
	char *hex = ft_itox(n);
	ft_putstr(hex);
}

size_t print_blocks(t_block *block)
{
	size_t total_size;

	total_size = 0;
	while (block)
	{
		if (block->free == 0)
		{
			ft_putnbr((int)block + sizeof(t_block));
			write(1, " - ", 3);
			ft_putnbr((int)block + block->size + sizeof(t_block));
			write(1, " : ", 3);
			ft_putnbr(block->size);
			total_size += block->size;
			ft_putstr(" bytes\n");
		}
		block = block->next;
	}
	return (total_size);
}

void show_alloc_mem(void)
{
	size_t total_size;
	t_region *region;

	total_size = 0;
	region = regions[0];
	while (region)
	{
		ft_putstr("TINY : ");
		ft_putnbr((int)region);
		ft_putstr("\n");
		total_size += print_blocks(region->blocks);
	}
	region = regions[1];
	while (region)
	{
		ft_putstr("SMALL : ");
		ft_puthex((int)region);
		ft_putstr("\n");
		total_size += print_blocks(region->blocks);
	}
	region = regions[2];
	while (region)
	{
		ft_putstr("LARGE : ");
		ft_puthex((int)region);
		ft_putstr("\n");
		total_size += print_blocks(region->blocks);
	}
	ft_putstr("Total: ");
	ft_putnbr(total_size);
	ft_putstr(" bytes\n");
}
