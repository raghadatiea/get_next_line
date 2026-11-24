#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("Line %d: [%s]", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}
