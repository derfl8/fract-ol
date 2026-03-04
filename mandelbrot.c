/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:28:15 by abegou            #+#    #+#             */
/*   Updated: 2026/03/04 13:19:13 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
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

void	render(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			if (env->m_or_j == 0)
				render_mandel_pixel(env, x, y);
			else if (env->m_or_j == 1)
				render_julia_pixel(env, x, y);
			x++;
		}
		y++;
	}
	mlx_clear_window(env->mlx, env->win, (mlx_color){.a = 0xff});
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int	do_mandelbrot(void)
{
	t_env	env;

	env.m_or_j = 0;
	init_window(&env, "Mandelbrot");
	env.min_x = -2.0;
	env.max_x = 2.0;
	env.min_y = -2.0;
	env.max_y = 2.0;
	render(&env);
	mlx_on_event(env.mlx, env.win, MLX_MOUSEWHEEL, mouse_wheel_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_KEYDOWN, key_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_WINDOW_EVENT, window_hook, &env);
	mlx_add_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
