/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:13:16 by abegou            #+#    #+#             */
/*   Updated: 2026/02/14 17:35:20 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_check(char *char_r, char *char_i)
{
	double	float_r;
	double	float_i;

	float_r = ft_atof(char_r);
	float_i = ft_atof(char_i);
	if ((float_r <= 2.0 && float_r >= -2.0)
		&& (float_i <= 2.0 && float_r >= -2.0))
		do_julia();
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
