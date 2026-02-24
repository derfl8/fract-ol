/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:15:48 by abegou            #+#    #+#             */
/*   Updated: 2026/02/14 17:00:58 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	write(1, "Bad arguments.\n", 15);
	write(1, "For Julia:\n", 11);
	write(1, "arg 1: Julia/julia\narg 2: -2.0 2.0\narg 3: -2.0 2.0\n", 51);
	write(1, "For Mandelbrot:\narg 1: Mandelbrot/mandelbrot\n", 46);
	return ;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	dot_killer(char *f_value, int i, double *ret)
{
	double	fract;

	fract = 0.1;
	if (f_value[i] == '.')
	{
		i++;
		while (f_value[i] >= '0' && f_value[i] <= '9')
		{
			*ret += (f_value[i] - 48) * fract;
			i++;
			fract *= 0.1;
		}
	}
}

double	ft_atof(char *f_value)
{
	int		i;
	int		sign;
	double	ret;

	i = 0;
	sign = 1;
	ret = 0;
	if (f_value[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (f_value[i] >= '0' && f_value[i] <= '9')
	{
		ret = ret * 10 + f_value[i] - 48;
		i++;
	}
	dot_killer(f_value, i, &ret);
	return (ret * sign);
}
