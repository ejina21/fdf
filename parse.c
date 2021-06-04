#include "fdf.h"

int	parse(int fd, int **array, t_long *len)
{
	char	*line;
	char	**head;

	while (get_next_line(fd, &line))
	{
		head = ft_split(line, ' ');
		if (!head)
			return (0);
		free(line);
		while (head[len->i])
			len->i += 1;
		array[len->number_line] = malloc(sizeof(int) * len->i);
		if (!array[len->number_line])
			return (0);
		len->i = -1;
		while (head[++(len->i)])
			array[len->number_line][len->i] = ft_atoi(head[len->i]);
		len->number_line += 1;
		free(head);
	}
	free(line);
	return (1);
}

int	get_arr(char **argv, int ***array)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	*array = malloc(sizeof(int *) * i);
	if (!*array)
		return (0);
	return (1);
}
