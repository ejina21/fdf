#include "fdf.h"

static void	draw_line_to(t_draw *draw, t_mlx *mlx, t_dot dot1, t_dot dot2)
{
	int	err;
	int	e2;

	err = draw->dx + draw->dy;
	while (1)
	{
		if (dot1.x + 700 < 1920 && dot1.y + 50 < 1080
			&& dot1.x + 700 > 0 && dot1.y + 50 > 0)
			mlx_pixel_put(mlx->mlx, mlx->mlx_win,
				dot1.x + 700, dot1.y + 50, 0x0000FF);
		if (dot1.x == dot2.x && dot1.y == dot2.y)
			break ;
		e2 = 2 * err;
		if (e2 >= draw->dy)
		{
			err += draw->dy;
			dot1.x += draw->sx;
		}
		if (e2 <= draw->dx)
		{
			err += draw->dx;
			dot1.y += draw->sy;
		}
	}
}

void	draw_line(t_dot dot1, t_dot dot2, t_mlx *mlx)
{
	t_draw	draw;

	draw.dx = abs(dot2.x - dot1.x);
	if (dot1.x < dot2.x)
		draw.sx = 1;
	else
		draw.sx = -1;
	draw.dy = -abs(dot2.y - dot1.y);
	if (dot1.y < dot2.y)
		draw.sy = 1;
	else
		draw.sy = -1;
	draw_line_to(&draw, mlx, dot1, dot2);
}
