#include <stdio.h>

int sum(int a, int b)
{
	int c;
	c = a + b;

	return c;
}

int main(int argc, char* argv[])
{
	int a, b;
	int c = 0;
	int i;

	for (i=0; i<10; i++)
	{
		printf("a + b is %d\n", sum(a,b));
		a = a + 3;
		b = b + 5;
	}	

	printf("(a + b) / c is %d\n", sum(a,b)/c);
	return 0;
}
