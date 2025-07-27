#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "rushlib.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;
	
	int fd = open(argv[1], O_RDONLY);
	char *line;
	while ((line = ft_getline(fd)) != (char *)1)
		printf("found line: %s\n", line);
	close(fd);
	return 0;
}
