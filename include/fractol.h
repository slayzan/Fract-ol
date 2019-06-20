/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:02:14 by humarque          #+#    #+#             */
/*   Updated: 2019/06/20 17:40:30 by humarque         ###   ########.fr       */
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
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}					t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_img	img;
}				t_mlx;

typedef	struct s_fract
{
	int iter;
	int zx;
	int zy;
	int zoom;
	int itermax;
	int x0;
	int y0;
	int x1;
	int y1;
	int y;
	int x;
	int num;
	t_mlx mlx;	

}				t_fract;

#endif
