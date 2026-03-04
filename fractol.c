/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:13:16 by abegou            #+#    #+#             */
/*   Updated: 2026/03/04 16:29:57 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_check(char *char_r, char *char_i)
{
	t_env	env;

	env.cr = ft_atof(char_r);
	env.ci = ft_atof(char_i);
	if ((env.cr <= 2.0 && env.cr >= -2.0)
		&& (env.ci <= 2.0 && env.ci >= -2.0))
		do_julia(env.cr, env.ci);
	else
		ft_error();
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 4 && (ft_strcmp(av[1], "Julia") == 0
			|| ft_strcmp(av[1], "julia") == 0))
		julia_check(av[2], av[3]);
	else if (ac == 2 && (ft_strcmp(av[1], "Mandelbrot") == 0
			|| ft_strcmp(av[1], "mandelbrot") == 0))
		do_mandelbrot();
	else
	{
		ft_error();
		return (0);
	}
}
