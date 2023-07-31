#include <stdio.h>
#include <unistd.h>

/**
 * infinite_while - infinte loop
 *
 * Return: always 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}


/**
 * main- creates 5 zombie processes
 *
 * Return: always 0
 */
int main(void)
{
	int i;
	pid_t pid;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
			break;
		if (pid != 0)
			printf("Zombie process created, PID: %d\n", pid);
	}
	if (pid != 0)
		infinite_while();

	return (0);
}
