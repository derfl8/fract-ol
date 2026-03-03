/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:40:57 by abegou            #+#    #+#             */
/*   Updated: 2026/03/03 19:59:50 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static double	zoom_min(double min, double max, double factor)
{
	return ((min + max) / 2) - ((max - min) * factor / 2);
}

static double	zoom_max(double min, double max, double factor)
{
	return ((min + max) / 2) + ((max - min) * factor / 2);
}

void mouse_wheel_hook(int button, void* param)
{
	t_env	*env;
	double temp;

	env = (t_env *)param;
	if (button == 1)
    {
		temp = zoom_min(env->min_x, env->max_x, 0.9);
	    env->max_x = zoom_max(env->min_x, env->max_x, 0.9);
		env->min_x = temp;
		temp = zoom_min(env->min_y, env->max_y, 0.9);
	    env->max_y = zoom_max(env->min_y, env->max_y, 0.9);
		env->min_y = temp;
    }
    if (button == 2)
    {
		temp = zoom_min(env->min_x, env->max_x, 1.1);
	    env->max_x = zoom_max(env->min_x, env->max_x, 1.1);
		env->min_x = temp;
		temp = zoom_min(env->min_y, env->max_y, 1.1);
	    env->max_y = zoom_max(env->min_y, env->max_y, 1.1);
		env->min_y = temp;
    }
	render_mandelbrot(&env);
}