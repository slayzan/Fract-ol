/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:16:07 by humarque          #+#    #+#             */
/*   Updated: 2019/08/13 03:08:57 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_color(t_fract *fract)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((fract->iter * fract->color.r)
			/ (fract->itermax * fract->color.depth));
	g = ((fract->iter * fract->color.g)
			/ (fract->itermax * fract->color.depth));
	b = ((fract->iter * fract->color.b)
			/ (fract->itermax * fract->color.depth));
	fract->mlx.img.data[((int)(fract->y * WIDTH + (int)fract->x) * 4) + 2] = r;
	fract->mlx.img.data[(((int)fract->y * WIDTH + (int)fract->x) * 4) + 1] = g;
	fract->mlx.img.data[((int)(fract->y * WIDTH + (int)fract->x) * 4)] = b;
}

void	black(t_fract *fract)
{
	fract->mlx.img.data[((int)(fract->y * WIDTH + (int)fract->x) * 4) + 2] = 0;
	fract->mlx.img.data[(((int)fract->y * WIDTH + (int)fract->x) * 4) + 1] = 0;
	fract->mlx.img.data[(((int)fract->y * WIDTH + (int)fract->x) * 4)] = 0;
}

double		ft_dabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
