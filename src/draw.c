/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:16:42 by humarque          #+#    #+#             */
/*   Updated: 2019/08/13 03:08:15 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		mandelbrot(t_fract *fract)
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
		fract->zx = (fract->zx * fract->zx) -
			(fract->zy * fract->zy) + fract->x0;
		fract->zy = 2 * temp * fract->zy + fract->y0;
		fract->iter++;
	}
	if (fract->iter == fract->itermax)
		black(fract);
	else
		draw_color(fract);
}

void		ft_julia(t_fract *fract)
{
	double temp;

	temp = 0;
	fract->zx = (fract->x - fract->x1 / 2) / fract->zoom;
	fract->zy = (fract->y - fract->y1 / 2) / fract->zoom;
	fract->iter = 0;
	fract->x0 = fract->x2;
	fract->y0 = fract->y2;
	while (fract->zx * fract->zx + fract->zy * fract->zy < 4
			&& fract->iter < fract->itermax)
	{
		temp = fract->zx;
		fract->zx = fract->zx * fract->zx - fract->zy * fract->zy + fract->x0;
		fract->zy = 2 * temp * fract->zy + fract->y0;
		fract->iter++;
	}
	if (fract->iter == fract->itermax)
		black(fract);
	else
		draw_color(fract);
}

void		ft_burningship(t_fract *fract)
{
	double temp;

	temp = 0;
	fract->zx = (fract->x - fract->x1 / 2) / fract->zoom - 0.5;
	fract->zy = (fract->y - fract->y1 / 2) / fract->zoom - 0.5;
	fract->x0 = fract->zx;
	fract->y0 = fract->zy;
	fract->iter = 0;
	while (fract->zx * fract->zx + fract->zy * fract->zy < 4
			&& fract->iter < fract->itermax)
	{
		temp = fract->zx;
		fract->zx = fract->zx * fract->zx - fract->zy * fract->zy + fract->x0;
		fract->zy = 2 * ft_dabs(temp * fract->zy) + fract->y0;
		fract->iter++;
	}
	if (fract->iter == fract->itermax)
		black(fract);
	else
		draw_color(fract);
}

