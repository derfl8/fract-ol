/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:29:53 by abegou            #+#    #+#             */
/*   Updated: 2026/03/04 10:10:03 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_hook(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void	key_hook(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == 41)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_context(env->mlx);
		exit(0);
	}
}

void	window_hook(int event, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (event == 0)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_context(env->mlx);
		exit(0);
	}
}

mlx_color	get_simple_color(int iter)
{
	mlx_color	color;

	if (iter == 100)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	else if (iter < 50)
	{
		color.r = 0;
		color.g = 0;
		color.b = (uint8_t)(iter * 255 / 50);
	}
	else 
	{
		color.g = 0;
		color.b = 255;
		color.r = (uint8_t)(iter * 255 / 100);
	}
	color.a = 255;
	return (color);
}

void	init_window(t_env *env, char *title)
{
	mlx_window_create_info	info;

	env->mlx = mlx_init();
	info.render_target = 0;
	info.title = title;
	info.width = 800;
	info.height = 800;
	info.is_fullscreen = 0;
	info.is_resizable = 0;
	env->win = mlx_new_window(env->mlx, &info);
	env->img = mlx_new_image(env->mlx, 800, 800);
}
