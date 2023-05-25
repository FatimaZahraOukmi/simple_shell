#include <stdio.h>
#include "Env_vs_environ.h"

int main(void)
{
	someVariable = 10;
	someFunction(someVariable);

	return (0);
}

void someFunction(int variable)
{
	printf("The value of someVariable is: %d\n", variable);
}
