#include "fdf.h"

void	render(t_mlx *vars)
{
	void	*tmp;

	tmp = vars->img;
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	draw_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	mlx_destroy_image(vars->mlx, tmp);
}

static void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_line_to(t_dots dot1, t_dots dot2, t_mlx *mlx)
{
	int	err;
	int	e2;

	err = mlx->dx + mlx->dy;
	while (1)
	{
		if (dot1.x + 700 < 1920 && dot1.y + 500 < 1080
			&& dot1.x + 700 > 0 && dot1.y + 500 > 0)
			my_mlx_pixel_put(mlx,
				dot1.x + 700, dot1.y + 500, 0x0000FF);
		if (dot1.x == dot2.x && dot1.y == dot2.y)
			break ;
		e2 = 2 * err;
		if (e2 >= mlx->dy)
		{
			err += mlx->dy;
			dot1.x += mlx->sx;
		}
		if (e2 <= mlx->dx)
		{
			err += mlx->dx;
			dot1.y += mlx->sy;
		}
	}
}

void	draw_line(t_dots dot1, t_dots dot2, t_mlx *mlx)
{
	mlx->dx = abs(dot2.x - dot1.x);
	if (dot1.x < dot2.x)
		mlx->sx = 1;
	else
		mlx->sx = -1;
	mlx->dy = -abs(dot2.y - dot1.y);
	if (dot1.y < dot2.y)
		mlx->sy = 1;
	else
		mlx->sy = -1;
	draw_line_to(dot1, dot2, mlx);
}

void	draw_scene(t_mlx *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1920, 1080, "fdf");
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->k = 10;
	vars->kl = 0;
	draw_image(vars);
	mlx_hook(vars->mlx_win, 2, 0, key_hook, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	mlx_loop(vars->mlx);
}
