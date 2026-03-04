/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:46:50 by abegou            #+#    #+#             */
/*   Updated: 2026/03/04 12:10:33 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int max_iter)
{
	t_env	env;
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
		zr = new_zr + env.cr;
		zi = new_zi + env.ci;
		i++;
	}
	return (i);
}

static void	render_julia_pixel(t_env *env, int x, int y)
{
	int			iter;
	mlx_color	color;

	iter = julia(100);
	color = get_simple_color(iter);
	mlx_set_image_pixel(env->mlx, env->img, x, y, color);
}

static void	render_julia(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			render_julia_pixel(env, x, y);
			x++;
		}
		y++;
	}
	mlx_clear_window(env->mlx, env->win, (mlx_color){.a = 0xff});
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int	do_julia(void)
{
	t_env	env;

	init_window(&env, "Julia");
	env.min_x = -2.0;
	env.max_x = 2.0;
	env.min_y = -2.0;
	env.max_y = 2.0;
	render_julia(&env);
	mlx_on_event(env.mlx, env.win, MLX_MOUSEWHEEL, mouse_wheel_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_KEYDOWN, key_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_WINDOW_EVENT, window_hook, &env);
	mlx_add_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
