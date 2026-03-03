/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:40:57 by abegou            #+#    #+#             */
/*   Updated: 2026/03/03 19:41:24 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void mouse_wheel_hook(int button, void* param)
{
	t_env	*env;

	env = (t_env *)param;
	if (button == 1)
    {
    	env->min_x = ((env->min_x + env->max_x) / 2) - ((env->max_x - env->min_x) * 0.9 / 2);
	    env->max_x = ((env->min_x + env->max_x) / 2) + ((env->max_x - env->min_x) * 0.9 / 2);
	    env->min_y = ((env->min_y + env->max_y) / 2) - ((env->max_y - env->min_y) * 0.9 / 2);
	    env->max_y = ((env->min_y + env->max_y) / 2) + ((env->max_y - env->min_y) * 0.9 / 2);
    }
    if (button == 2)
    {
    	env->min_x = ((env->min_x + env->max_x) / 2) - ((env->max_x - env->min_x) * 1.1 / 2);
	    env->max_x = ((env->min_x + env->max_x) / 2) + ((env->max_x - env->min_x) * 1.1 / 2);
	    env->min_y = ((env->min_y + env->max_y) / 2) - ((env->max_y - env->min_y) * 1.1 / 2);
	    env->max_y = ((env->min_y + env->max_y) / 2) + ((env->max_y - env->min_y) * 1.1 / 2);
    }
	render_mandelbrot(&env);
}