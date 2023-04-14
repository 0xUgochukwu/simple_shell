#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t mypid = getppid(), pid = getpid();

	printf("Parent process %u, child process %u\n", mypid, pid);
}
