
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 256

int main(int ac, char **av)
{
	char buf[MAX_BUF];
	FILE *fp;

	if (ac != 2)
	{
		printf("Usage: %s <filename>\n", av[0]);
		exit(1);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: could not open file %s\n", av[1]);
		exit(1);
	}
	
	fgets(buf, MAX_BUF, fp);
	fclose(fp);
	
	printf("Maximum PID value: %s", buf);
	return (0);
}
