#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	/*
	int len = atoi(av[1]);
	len = len & 0;

	printf("len = %d	- sizeof(len) = %ld\n", len, sizeof(len));
	return (0);
	*/
	int	num = atoi(av[1]);
	int     count;

        count = 0;
        while (num && ++count)
                num >>= 1;
	printf("num = %i	- len = %d\n", atoi(av[1]), count);
	return (0);
}
