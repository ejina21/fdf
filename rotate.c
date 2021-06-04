#include "fdf.h"

void	rotate_z(t_dot *dots, float *degree)
{
	int	x;
	int	y;

	x = dots[0].x * cosf(degree[2]) - dots[0].y * sinf(degree[2]);
	y = dots[0].x * sinf(degree[2]) + dots[0].y * cosf(degree[2]);
	dots[0].x = x;
	dots[0].y = y;
	x = dots[1].x * cosf(degree[2]) - dots[1].y * sinf(degree[2]);
	y = dots[1].x * sinf(degree[2]) + dots[1].y * cosf(degree[2]);
	dots[1].x = x;
	dots[1].y = y;
	x = dots[2].x * cosf(degree[2]) - dots[2].y * sinf(degree[2]);
	y = dots[2].x * sinf(degree[2]) + dots[2].y * cosf(degree[2]);
	dots[2].x = x;
	dots[2].y = y;
	x = dots[3].x * cosf(degree[2]) - dots[3].y * sinf(degree[2]);
	y = dots[3].x * sinf(degree[2]) + dots[3].y * cosf(degree[2]);
	dots[3].x = x;
	dots[3].y = y;
}

void	rotate_x(t_dot *dots, float *degree)
{
	int	z;
	int	y;

	y = dots[0].y * cosf(degree[0]) + dots[0].z * sinf(degree[0]);
	z = -dots[0].y * sinf(degree[0]) + dots[0].z * cosf(degree[0]);
	dots[0].y = y;
	dots[0].z = z;
	y = dots[1].y * cosf(degree[0]) + dots[1].z * sinf(degree[0]);
	z = -dots[1].y * sinf(degree[0]) + dots[1].z * cosf(degree[0]);
	dots[1].y = y;
	dots[1].z = z;
	y = dots[2].y * cosf(degree[0]) + dots[2].z * sinf(degree[0]);
	z = -dots[2].y * sinf(degree[0]) + dots[2].z * cosf(degree[0]);
	dots[2].y = y;
	dots[2].z = z;
	y = dots[3].y * cosf(degree[0]) + dots[3].z * sinf(degree[0]);
	z = -dots[3].y * sinf(degree[0]) + dots[3].z * cosf(degree[0]);
	dots[3].y = y;
	dots[3].z = z;
}

void	rotate_y(t_dot *dots, float *degree)
{
	int	z;
	int	x;

	x = dots[0].x * cosf(degree[1]) + dots[0].z * sinf(degree[1]);
	z = -dots[0].x * sinf(degree[1]) + dots[0].z * cosf(degree[1]);
	dots[0].x = x;
	dots[0].z = z;
	x = dots[1].x * cosf(degree[1]) + dots[1].z * sinf(degree[1]);
	z = -dots[1].x * sinf(degree[1]) + dots[1].z * cosf(degree[1]);
	dots[1].x = x;
	dots[1].z = z;
	x = dots[2].x * cosf(degree[1]) + dots[2].z * sinf(degree[1]);
	z = -dots[2].x * sinf(degree[1]) + dots[2].z * cosf(degree[1]);
	dots[2].x = x;
	dots[2].z = z;
	x = dots[3].x * cosf(degree[1]) + dots[3].z * sinf(degree[1]);
	z = -dots[3].x * sinf(degree[1]) + dots[3].z * cosf(degree[1]);
	dots[3].x = x;
	dots[3].z = z;
}
