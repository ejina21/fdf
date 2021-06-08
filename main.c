#include "fdf.h"

void	pull_dots(t_mlx *vars, int len, int ln)
{
	vars->dot1.x = len * vars->k;
	vars->dot1.y = ln * vars->k;
	vars->dot1.z = vars->array[ln][len] * (vars->k / 2 + vars->kl);
	vars->dot2.x = (len + 1) * vars->k;
	vars->dot2.y = (ln + 1) * vars->k;
	vars->dot2.z = vars->array[ln + 1][len + 1] * (vars->k / 2 + vars->kl);
	vars->dot3.x = (len + 1) * vars->k;
	vars->dot3.y = ln * vars->k;
	vars->dot3.z = vars->array[ln][len + 1] * (vars->k / 2 + vars->kl);
	vars->dot4.x = len * vars->k;
	vars->dot4.y = (ln + 1) * vars->k;
	vars->dot4.z = vars->array[ln + 1][len] * (vars->k / 2 + vars->kl);
}

void	draw_image(t_mlx *vars)
{
	int		len;
	int		ln;

	ln = -1;
	while (++ln < vars->number_line - 1)
	{
		len = -1;
		while (++len < vars->i - 1)
		{
			pull_dots(vars, len, ln);
			rotate_z(vars);
			rotate_x(vars);
			rotate_y(vars);
			draw_line(vars->dot1, vars->dot3, vars);
			draw_line(vars->dot1, vars->dot4, vars);
			draw_line(vars->dot2, vars->dot3, vars);
			draw_line(vars->dot2, vars->dot4, vars);
		}
	}
}

void	change_degree(int keycode, t_mlx *vars)
{
	if (keycode == 89)
		vars->degx += 2 * M_PI / 180;
	else if (keycode == 91)
		vars->degx -= 2 * M_PI / 180;
	else if (keycode == 86)
		vars->degy += 2 * M_PI / 180;
	else if (keycode == 87)
		vars->degy -= 2 * M_PI / 180;
	else if (keycode == 83)
		vars->degz += 2 * M_PI / 180;
	else if (keycode == 84)
		vars->degz -= 2 * M_PI / 180;
}

int	key_hook(int keycode, t_mlx *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	if (keycode == 126)
		vars->k += 2;
	else if (keycode == 125)
		vars->k -= 2;
	else if (keycode == 123)
		vars->kl += 1;
	else if (keycode == 124)
		vars->kl -= 1;
	else
		change_degree(keycode, vars);
	render(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_mlx	vars;

	if (argc != 2)
		return (1);
	vars.number_line = 0;
	vars.i = 0;
	vars.array = 0;
	if (!get_arr(argv, &vars))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	if (!parse(fd, &vars))
		return (1);
	close(fd);
	vars.degx = -70 * M_PI / 180;
	vars.degz = 40 * M_PI / 180;
	vars.degy = -5 * M_PI / 180;
	draw_scene(&vars);
	return (0);
}
