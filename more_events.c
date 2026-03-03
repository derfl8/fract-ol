/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:40:57 by abegou            #+#    #+#             */
/*   Updated: 2026/03/03 13:11:50 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void mouse_wheel_hook(int button, void* param)
{
	t_env	*env;

	env = (t_env *)param;
	if (button)
    {
        printf("%d\n", button);
    }
}