/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:02:49 by abegou            #+#    #+#             */
/*   Updated: 2026/02/24 16:28:28 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "MacroLibX/includes/mlx.h"

typedef struct s_env
{
    mlx_context mlx;
    mlx_window  win;
    mlx_image   img;
    double      min_x;
    double      max_x;
    double      min_y;
    double      max_y;
}   t_env;

int			do_fract(void);
int			ft_strcmp(char *s1, char *s2);
void		ft_error(void);
void		julia_check(char *char_r, char *char_i);
double		ft_atof(char *dot_n);
void		dot_killer(char *f_value, int i, double *ret);
void		init_window(t_env *env, char *title);
mlx_color	get_simple_color(int iter);
int			do_mandelbrot(void);
int			mandelbrot(double cr, double ci, int max_iter);
int			do_mandelbrot(void);
int			do_julia(void);
void		loop_hook(void *param);
void		key_hook(int keycode, void *param);
void		window_hook(int event, void *param);
void mouse_wheel_hook(int button, void* param);

#endif
