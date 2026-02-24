/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:46:50 by abegou            #+#    #+#             */
/*   Updated: 2026/02/15 19:47:33 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	do_julia(void)
{
	t_env					env;
	mlx_window_create_info	info;
	mlx_color				color;
	int						x;
	int						y;

	env.mlx = mlx_init();
	info.render_target = 0;
	info.title = "Julia";
	info.width = 800;
	info.height = 800;
	info.is_fullscreen = 0;
	info.is_resizable = 0;
	env.win = mlx_new_window(env.mlx, &info);
	env.img = mlx_new_image(env.mlx, 800, 800);
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			color.r = (uint8_t)(x * 255 / 800);
			color.g = (uint8_t)(y * 255 / 800);
			color.b = 0;
			color.a = 255;
			mlx_set_image_pixel(env.mlx, env.img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_on_event(env.mlx, env.win, MLX_KEYDOWN, key_hook, &env);
	mlx_on_event(env.mlx, env.win, MLX_WINDOW_EVENT, window_hook, &env);
	mlx_add_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
