/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:02:14 by humarque          #+#    #+#             */
/*   Updated: 2019/08/13 03:09:11 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# define HEIGHT 1280
# define WIDTH  1640

typedef	struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef struct	s_color
{
	double		depth;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	struct	s_fract
{
	int			iter;
	int			julia;
	double		zx;
	double		zy;
	double		zoom;
	int			itermax;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		y;
	double		x;
	int			num;
	t_mlx		mlx;
	t_color		color;

}				t_fract;

void			ft_burningship(t_fract *fract);
void			init_window(t_fract *fract);
void			mandelbrot(t_fract *fract);
void			ft_julia(t_fract *fract);
void			draw_color(t_fract *fract);
void			black(t_fract *fract);
int				mouse_motion(int x, int y, t_fract *fract);
void			make_draw(t_fract *fract);
int				key_hook(int keycode, t_fract *fract);
int				mouse_hook(int keycode, int x, int y, t_fract *fract);
void			ft_init(t_fract *fract);
void			ft_restart(int keycode, t_fract *fract);
void			iter_color(int keycode, t_fract *fract);
void			ft_move(int keycode, t_fract *fract);
void			ft_print_error();
double			ft_dabs(double x);
#endif
