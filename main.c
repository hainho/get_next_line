#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd01;
	char *line = NULL;

	fd01 = open("./tester/files/multiple_line_no_nl", O_RDWR);
	// fd02 = open("gnl2.txt", O_RDONLY);
	// fd03 = open("gnl3.txt", O_RDONLY);

	line = get_next_line(fd01);
	printf("%d\n", fd01);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd01);
	printf("%d\n", fd01);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd01);
	printf("%d\n", fd01);
	printf("%s\n", line);
	free(line);
	close(fd01);

	fd01 = open("./tester/files/multiple_line_no_nl", O_RDWR);
	// fd02 = open("gnl2.txt", O_RDONLY);
	// fd03 = open("gnl3.txt", O_RDONLY);

	line = get_next_line(fd01);
	printf("%d\n", fd01);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd01);
	printf("%d\n", fd01);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd01);
	printf("%d\n", fd01);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd01);
	printf("%d\n", fd01);
	printf("%s\n", line);
	free(line);
	close(fd01);

	fd01 = open("./tester/files/multiple_line_no_nl", O_RDWR);
	// fd02 = open("gnl2.txt", O_RDONLY);
	// fd03 = open("gnl3.txt", O_RDONLY);


	while(1)
	{
	//FD 01
	line = get_next_line(fd01);
	
	printf("%s\n", line);
	if (line == NULL)
		break;
	free(line);

	
	}

	//system("leaks a.out");
	return (0);
}