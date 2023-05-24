#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 256

int main()
{
	char buf[MAX_BUF];
	FILE *fp;

	fp = fopen("/proc/sys/kernel/pid_max", "r");
	if (fp == NULL)
	{
		printf("Error: could not open /proc/sys/kernel/pid_max\n");
		exit(1);
	}
	fgets(buf, MAX_BUF, fp);
	fclose(fp);
	
	printf("Maximum PID value: %s", buf);
	return (0);
}
