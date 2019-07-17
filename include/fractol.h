/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:02:14 by humarque          #+#    #+#             */
/*   Updated: 2019/07/17 18:36:27 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# define  HEIGHT 720
# define  WIDTH  1280

typedef	struct		s_img
{
	void	*img_ptr;
	char		*data;
	int		bpp;
	int		size_l;
	int		endian;
}					t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;


typedef struct s_color
{
	double depth;
	int r;
	int g;
	int b;
}				t_color;

typedef	struct s_fract
{
	int iter;
	int julia;
	double zx;
	double zy;
	double zoom;
	int itermax;
	double x0;
	double y0;
	double x1;
	double y1;
	double x2;
	double y2;
	double y;
	double x;
	int num;
	t_mlx mlx;
	t_color color;

}				t_fract;

void	init_window(t_fract *fract);
void	mandelbrot(t_fract *fract);
void	ft_julia(t_fract *fract);
void	draw_color(t_fract *fract);
void	black(t_fract *fract);
#endif
