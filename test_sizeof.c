#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int len = atoi(av[1]);
	len = len & 0;

	printf("len = %d	- sizeof(len) = %ld\n", len, sizeof(len));
	return (0);
}
