/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:16:42 by humarque          #+#    #+#             */
/*   Updated: 2019/06/26 18:07:48 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(t_fract *fract)
{
	double temp;

	temp = 0;
	fract->zx = (fract->x - fract->x1 / 2) / fract->zoom - 0.5;
	fract->zy = (fract->y - fract->y1 / 2) / fract->zoom;
	fract->iter = 0;
	fract->x0 = fract->zx;
	fract->y0 = fract->zy;
	while (fract->zx * fract->zx + fract->zy * fract->zy < 4
			&& fract->iter < fract->itermax)
	{
		temp = fract->zx;
		fract->zx = fract->zx * fract->zx - fract->zy * fract->zy + fract->x0;
		fract->zy = 2 * temp * fract->zy + fract->y0;
		fract->iter++;
	}
	if (fract->iter == fract->itermax)
		fract->mlx.img.data[fract->x * WIDTH + fract->y] = 0xFFFFFF;
}
