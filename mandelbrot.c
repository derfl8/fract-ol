/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:28:15 by abegou            #+#    #+#             */
/*   Updated: 2026/02/15 20:56:07 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	new_zr;
	double	new_zi;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (i < max_iter)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		new_zr = zr * zr - zi * zi;
		new_zi = 2 * zr * zi;
		zr = new_zr + cr;
		zi = new_zi + ci;
		i++;
	}
	return (i);
}

static void	render_mandel_pixel(t_env *env, int x, int y)
{
	double		cr;
	double		ci;
	int			iter;
	mlx_color	color;

	cr = env->min_x + (double)x * (env->max_x - env->min_x) / 800.0;
	ci = env->min_y + (double)y * (env->max_y - env->min_y) / 800.0;
	iter = mandelbrot(cr, ci, 100);
	color = get_simple_color(iter);
	mlx_set_image_pixel(env->mlx, env->img, x, y, color);
}

static void	render_mandelbrot(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			render_mandel_pixel(env, x, y);
			x++;
		}
		y++;
	}
}

int	do_mandelbrot(void)
{
	t_env	env;

	init_window(&env, "Mandelbrot");
	render_mandelbrot(&env);
	mlx_on_event(env.mlx, env.win, MLX_KEYDOWN, key_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_WINDOW_EVENT, window_hook, &env);
	mlx_add_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
