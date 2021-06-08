#include "fdf.h"

void	rotate_z(t_mlx *vars)
{
	int	x;
	int	y;

	x = vars->dot1.x * cosf(vars->degz) - vars->dot1.y * sinf(vars->degz);
	y = vars->dot1.x * sinf(vars->degz) + vars->dot1.y * cosf(vars->degz);
	vars->dot1.x = x;
	vars->dot1.y = y;
	x = vars->dot2.x * cosf(vars->degz) - vars->dot2.y * sinf(vars->degz);
	y = vars->dot2.x * sinf(vars->degz) + vars->dot2.y * cosf(vars->degz);
	vars->dot2.x = x;
	vars->dot2.y = y;
	x = vars->dot3.x * cosf(vars->degz) - vars->dot3.y * sinf(vars->degz);
	y = vars->dot3.x * sinf(vars->degz) + vars->dot3.y * cosf(vars->degz);
	vars->dot3.x = x;
	vars->dot3.y = y;
	x = vars->dot4.x * cosf(vars->degz) - vars->dot4.y * sinf(vars->degz);
	y = vars->dot4.x * sinf(vars->degz) + vars->dot4.y * cosf(vars->degz);
	vars->dot4.x = x;
	vars->dot4.y = y;
}

void	rotate_x(t_mlx *vars)
{
	int	z;
	int	y;

	y = vars->dot1.y * cosf(vars->degx) + vars->dot1.z * sinf(vars->degx);
	z = -vars->dot1.y * sinf(vars->degx) + vars->dot1.z * cosf(vars->degx);
	vars->dot1.y = y;
	vars->dot1.z = z;
	y = vars->dot2.y * cosf(vars->degx) + vars->dot2.z * sinf(vars->degx);
	z = -vars->dot2.y * sinf(vars->degx) + vars->dot2.z * cosf(vars->degx);
	vars->dot2.y = y;
	vars->dot2.z = z;
	y = vars->dot3.y * cosf(vars->degx) + vars->dot3.z * sinf(vars->degx);
	z = -vars->dot3.y * sinf(vars->degx) + vars->dot3.z * cosf(vars->degx);
	vars->dot3.y = y;
	vars->dot3.z = z;
	y = vars->dot4.y * cosf(vars->degx) + vars->dot4.z * sinf(vars->degx);
	z = -vars->dot4.y * sinf(vars->degx) + vars->dot4.z * cosf(vars->degx);
	vars->dot4.y = y;
	vars->dot4.z = z;
}

void	rotate_y(t_mlx *vars)
{
	int	z;
	int	x;

	x = vars->dot1.x * cosf(vars->degy) + vars->dot1.z * sinf(vars->degy);
	z = -vars->dot1.x * sinf(vars->degy) + vars->dot1.z * cosf(vars->degy);
	vars->dot1.x = x;
	vars->dot1.z = z;
	x = vars->dot2.x * cosf(vars->degy) + vars->dot2.z * sinf(vars->degy);
	z = -vars->dot2.x * sinf(vars->degy) + vars->dot2.z * cosf(vars->degy);
	vars->dot2.x = x;
	vars->dot2.z = z;
	x = vars->dot3.x * cosf(vars->degy) + vars->dot3.z * sinf(vars->degy);
	z = -vars->dot3.x * sinf(vars->degy) + vars->dot3.z * cosf(vars->degy);
	vars->dot3.x = x;
	vars->dot3.z = z;
	x = vars->dot4.x * cosf(vars->degy) + vars->dot4.z * sinf(vars->degy);
	z = -vars->dot4.x * sinf(vars->degy) + vars->dot4.z * cosf(vars->degy);
	vars->dot4.x = x;
	vars->dot4.z = z;
}
