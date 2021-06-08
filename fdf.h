#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>

typedef struct s_dots
{
	int	x;
	int	y;
	int	z;
}				t_dots;
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		number_line;
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	t_dots	dot1;
	t_dots	dot2;
	t_dots	dot3;
	t_dots	dot4;
	float	degx;
	float	degy;
	float	degz;
	int		**array;
	int		k;
	int		kl;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

void	draw_line(t_dots dot1, t_dots dot2, t_mlx *mlx);
int		get_arr(char **argv, t_mlx *vars);
int		parse(int fd, t_mlx *vars);
void	rotate_z(t_mlx	*vars);
void	rotate_x(t_mlx	*vars);
void	rotate_y(t_mlx	*vars);
int		get_next_line(int fd, char **line);
void	draw_image(t_mlx *vars);
void	render(t_mlx *vars);
void	draw_scene(t_mlx *vars);
int		key_hook(int keycode, t_mlx *vars);
#endif
