/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:46:50 by abegou            #+#    #+#             */
/*   Updated: 2026/03/04 16:29:44 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double zr, double zi, double cr, double ci)
{
	double	new_zr;
	double	new_zi;
	int		i;

	i = 0;
	while (i < 100)
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

void	render_julia_pixel(t_env *env, int x, int y)
{
	int			iter;
	mlx_color	color;
	double		zr;
	double		zi;

	zr = env->min_x + (double)x * (env->max_x - env->min_x) / 800.0;
	zi = env->min_y + (double)y * (env->max_y - env->min_y) / 800.0;
	iter = julia(zr, zi, env->cr, env->ci);
	color = get_simple_color(iter);
	mlx_set_image_pixel(env->mlx, env->img, x, y, color);
}

int	do_julia(double cr, double ci)
{
	t_env	env;

	env.m_or_j = 1;
	init_window(&env, "Julia");
	env.min_x = -2.0;
	env.max_x = 2.0;
	env.min_y = -2.0;
	env.max_y = 2.0;
	env.cr = cr;
	env.ci = ci;
	render(&env);
	mlx_on_event(env.mlx, env.win, MLX_MOUSEWHEEL, mouse_wheel_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_KEYDOWN, key_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_WINDOW_EVENT, window_hook, &env);
	mlx_add_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
