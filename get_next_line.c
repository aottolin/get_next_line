#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = get_read_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = get_line(save);
	save = get_rest(save);
	return (line);
}
/* La funcion 'get_read' buscara leer el 'fd' usando el while y la funcion 'read', lo hara de a 'x' cantidad de 'buffer_size', hasta que dentro de 'save' haya un '\n'. Si el buffer es 10, va a ir metiendo de a 10 bytes en 'save'. Cuando termine de meter esa info en 'save' mediante 'strjoin', comprobara si hay un '\n' y ahi no volvera a entrar... Dando paso a la siguiente funcion 'Get_Line', en donde se quedara con la linea que determina el '\n'. Con la funcion 'get_rest', eliminara lo anterior al '\n' y se quedara con lo siguiente al '\n' que leyo 'read'. */

char	*get_read_save(int fd, char *save)
{
	char	*buffer;
	int		nbchars;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nbchars = 1;
	while ((str_chr(save, '\n') == NULL) && nbchars > 0) 
	{
		nbchars = read(fd, buffer, BUFFER_SIZE);
		if (nbchars == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[nbchars] = '\0';
		save = str_join(save, buffer);
	}
	free(buffer);
	return (save);
}
/* Get_line crea un nuevo string llamado 'line', le asignara memoria con malloc. Para asignar la memoria exacta, coge a 'save' con la fc 'len_line' y calcula cuantos bytes hay hasta el primer '\n o '\0'. Una vez sabe la memoria exacta, coge 'save' y copia en 'line' su contentido hasta encontrarse con un '\n' o '\0'. En la posicion final de 'line' pondra un '\n'. Retornara la linea a escribir en pantalla. */

char	*get_line(char *save)
{
	int		x;
	char	*line;
	
	x = 0;
	if (!save[x])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (len_line(save) + 2));
	if (!line)
		return (NULL);
	while (save[x] != '\0' && save[x] != '\n')
	{
		line[x] = save[x];
		x++;
	}
	if (save[x] == '\n')
	{
		line[x] = '\n';
		x++;
	}
	line[x] = '\0';
	return (line);
}
/* 'Get_rest' recibe el string 'save' que contiene todo lo que ha leido y almacenado read. Lo que hara sera eliminar 'line' y esto se hara teniendo en cuenta el '\n o '\0'. Si el string 'save' contiene caracteres posteriores al '\n', los almacenara en 'rest' y retornara. Si lo que le sigue a '\n' es '\0' o en 'save' no hay nada, la funcion retornara NULLporque ha llegado al final del archivo."*/

char	*get_rest(char *save)
{
	int		i;
	int		n;
	char	*rest;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (str_len(save) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	n = 0;
	while (save[i] != '\0')
		rest[n++] = save[i++];
	rest[n] = '\0';
	free(save);
	return (rest);
}
