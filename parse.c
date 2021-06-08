#include "fdf.h"

static int	freem(char **p)
{
	int	j;

	j = 0;
	while (p[j])
	{
		free(p[j]);
		j++;
	}
	free(p);
	return (1);
}

int	parse(int fd, t_mlx *vars)
{
	char	*line;
	char	**head;

	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		head = ft_split(line, ' ');
		if (!head)
			return (0);
		free(line);
		while (head[vars->i])
			vars->i += 1;
		vars->array[vars->number_line] = malloc(sizeof(int) * vars->i);
		if (!vars->array[vars->number_line])
			return (0);
		vars->i = -1;
		while (head[++(vars->i)])
			vars->array[vars->number_line][vars->i] = ft_atoi(head[vars->i]);
		vars->number_line += 1;
		freem(head);
	}
	if (!line)
		return (0);
	free(line);
	return (1);
}

int	get_arr(char **argv, t_mlx *vars)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	if (!line)
		return (0);
	free(line);
	close(fd);
	vars->array = malloc(sizeof(int *) * i);
	if (!vars->array)
		return (0);
	return (1);
}
