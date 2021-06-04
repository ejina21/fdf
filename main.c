#include "fdf.h"

void	pull_dots(t_dot *dot, int **array, int len, int ln)
{
	int	k;
	int	kl;

	k = 20;
	kl = 3;
	dot[0].x = len * k;
	dot[0].y = ln * k;
	dot[0].z = array[ln][len] * kl;
	dot[1].x = (len + 1) * k;
	dot[1].y = (ln + 1) * k;
	dot[1].z = array[ln + 1][len + 1] * kl;
	dot[2].x = (len + 1) * k;
	dot[2].y = ln * k;
	dot[2].z = array[ln][len + 1] * kl;
	dot[3].x = len * k;
	dot[3].y = (ln + 1) * k;
	dot[3].z = array[ln + 1][len] * kl;
}

void	draw_image(t_long *lenght, float *degree, int **array, t_mlx *mlx)
{
	int		len;
	int		ln;
	t_dot	dot[4];

	ln = -1;
	while (++ln < lenght->number_line - 1)
	{
		len = -1;
		while (++len < lenght->i - 1)
		{
			pull_dots(dot, array, len, ln);
			rotate_z(dot, degree);
			rotate_x(dot, degree);
			rotate_y(dot, degree);
			draw_line(dot[0], dot[2], mlx);
			draw_line(dot[0], dot[3], mlx);
			draw_line(dot[1], dot[2], mlx);
			draw_line(dot[1], dot[3], mlx);
		}
	}
}

int	key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	draw_scene(t_long *len, float *degree, int **array)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1920, 1080, "test");
	draw_image(len, degree, array, &mlx);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		**array;
	t_long	len;
	float	degree[3];

	if (argc != 2)
		return (1);
	len.number_line = 0;
	len.i = 0;
	array = 0;
	if (!get_arr(argv, &array))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	if (!parse(fd, array, &len))
		return (1);
	close(fd);
	degree[0] = -70 * M_PI / 180;
	degree[2] = 40 * M_PI / 180;
	degree[1] = -5 * M_PI / 180;
	draw_scene(&len, degree, array);
	return (0);
}
