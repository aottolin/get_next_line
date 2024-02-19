#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		contador;
	char	*gnl;
	int		fd2;
	int		contador2;

	contador = 1;
	fd = open("test1.txt", O_RDONLY);
	while ((gnl = get_next_line(fd)) != NULL)
	{
		printf("== linea numero %d==%s", contador, gnl);
		contador++;
		free(gnl);
	}
	close(fd);

	contador2 = 1;
	fd2 = open("test3.txt", O_RDONLY);
	while ((gnl = get_next_line(fd2)) != NULL)
	{
		printf("== linea numero %d==%s", contador2, gnl);
		contador2++;
		free(gnl);
	}
	close(fd2);
	return (0);
}
