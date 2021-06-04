#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>
typedef struct s_long
{
	int	i;
	int	number_line;
}				t_long;

typedef struct s_draw
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
}				t_draw;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
}				t_dot;

void	draw_line(t_dot dot1, t_dot dot2, t_mlx *mlx);
int		get_arr(char **argv, int ***array);
int		parse(int fd, int **array, t_long *len);
void	rotate_z(t_dot *dots, float *degree);
void	rotate_x(t_dot *dots, float *degree);
void	rotate_y(t_dot *dots, float *degree);
int		get_next_line(int fd, char **line);
#endif
