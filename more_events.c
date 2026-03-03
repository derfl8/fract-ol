/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:40:57 by abegou            #+#    #+#             */
/*   Updated: 2026/03/03 15:49:59 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void mouse_wheel_hook(int button, void* param)
{
	t_env	*env;

	env = (t_env *)param;
	if (button == 1) //zoom
    {
    	env->min_x = min_x * 0.9;
	    env->max_x = 0.5;
	    env->min_y = -1;
	    env->max_y = 1;
    }
    if (button == 2) // dezoom
    {
        printf("%d\n", button);
    }
}