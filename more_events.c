/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:40:57 by abegou            #+#    #+#             */
/*   Updated: 2026/03/04 15:18:14 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	zoom_min(double min, double max, double factor)
{
	return (((min + max) / 2) - ((max - min) * factor / 2));
}

static double	zoom_max(double min, double max, double factor)
{
	return (((min + max) / 2) + ((max - min) * factor / 2));
}

void	mouse_wheel_hook(int button, void *param)
{
	t_env	*env;
	double	temp;
	double	factor;

	factor = 1;
	env = (t_env *)param;
	if (button == 1)
		factor = 0.9;
	else if (button == 2)
		factor = 1.1;
	temp = zoom_min(env->min_x, env->max_x, factor);
	env->max_x = zoom_max(env->min_x, env->max_x, factor);
	env->min_x = temp;
	temp = zoom_min(env->min_y, env->max_y, factor);
	env->max_y = zoom_max(env->min_y, env->max_y, factor);
	env->min_y = temp;
	render(env);
}
