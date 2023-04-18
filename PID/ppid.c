#include <stdio.h>
#include <unistd.h>
/**
 * main - main entry point
 * Return: 0
 */

int main(void)
{
	pid_t pid;

	pid = getpid(); // Get the current process ID
	printf("My PID is %d\n", pid);

	pid = getppid(); // Get the parent process ID
	printf("My parent's PID is %d\n", pid);

	return 0;
}
