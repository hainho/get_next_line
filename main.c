#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd01;
	char *line = NULL;

	fd01 = open("gnl.txt", O_RDWR);
	// fd02 = open("gnl2.txt", O_RDONLY);
	// fd03 = open("gnl3.txt", O_RDONLY);

	while(1)
	{
	//FD 01
	line = get_next_line(fd01);
	
	printf("FD01 | First Line | FD return %s\n", line);
	if (line == NULL)
		break;
	free(line);

	// //FD02
	// line = get_next_line(fd02);
	// printf("FD02 | First Line | FD return %s\n", line);
	// if (line == NULL)
	// 	break;
	// free(line);
	// //FD03
	// line = get_next_line(fd03);
	// printf("FD03 | First Line | FD return %s\n", line);
	// if (line == NULL)
	// 	break;
	// free(line);
	}

	system("leaks a.out");
	return (0);
}