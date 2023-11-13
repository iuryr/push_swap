#include <stdio.h>
#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("need more args\n");
		return (1);
	}

	int i = 1;
	while (i < argc)
	{
		if (is_int(argv[1]))
			printf("%s is integer\n", argv[1]);
		else
			printf("%s is NOT an integer\n", argv[1]);
		i++;
	}
}
