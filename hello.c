#include <stdio.h>

int main(int argc, char* argv[])
{
	int a, b;
	int c = 0;
	int i;

	for (i=0; i<10; i++)
	{
		printf("a + b is %d\n", a+b);
		a = a + 3;
		b = b + 5;
	}	

	printf("(a + b) / c is %d\n", (a+b)/c);
	return 0;
}
