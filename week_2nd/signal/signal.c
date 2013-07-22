#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void sig_int (int param)
{
	printf (" : Signal is ignored.\n");
}

int main(void)
{
	int i = 0;
	int num = 0;
	
	struct sigaction sigInt;

	sigInt.sa_handler = sig_int;
	sigemptyset(&sigInt.sa_mask);
	sigInt.sa_flags = 0;

	if (sigaction(SIGINT, &sigInt, 0) == -1)
	{
		perror("signal error.");
		exit(1);
	}

	for (i=0; i<10; i++)
	{
		printf ("%d\n", i);
		sleep(2);
	}
}
