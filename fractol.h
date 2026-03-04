/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:02:49 by abegou            #+#    #+#             */
/*   Updated: 2026/03/04 13:20:54 by abegou           ###   ########.fr       */
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
    double      cr;
    double      ci;
    int         m_or_j;
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
void    	render(t_env *env);
int			do_julia(void);
int         julia(double zr, double zi, double cr, double ci);
void    	render_julia_pixel(t_env *env, int x, int y);
void		loop_hook(void *param);
void		key_hook(int keycode, void *param);
void		window_hook(int event, void *param);
void 		mouse_wheel_hook(int button, void* param);

#endif
