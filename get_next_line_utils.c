#include "get_next_line.h"

size_t	str_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*str_chr(char *save, int newline)
{
	int	x;

	x = 0;
	if (!save)
		return (NULL);
	if (newline == '\0')
		return ((char *)&save[str_len(save)]);
	while (save[x] != newline && save[x] != '\0')
		x++;
	if (save[x] == newline)
		return (save);
	return (NULL);
}

char	*str_join(char *save, char *buffer)
{
	size_t	is;
	size_t	ib;
	char	*new;

	is = -1;
	ib = 0;
	if (!save)
	{
		save = (char *)malloc(1 * sizeof(char));
		save[0] = '\0';
	}
	if (!save || !buffer)
		return (NULL);
	new = (char *)malloc(((str_len(save) + str_len(buffer)) + 1 ) * sizeof(char));
	if (!new)
		return (NULL);
	if (save)
		while (save[++is] != '\0')
			new[is] = save[is];
	while (buffer[ib] != '\0')
		new[is++] = buffer[ib++];
	new[str_len(save) + str_len(buffer)] = '\0';
	free(save);
	return (new);
}

size_t	len_line(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	return (len);
}
