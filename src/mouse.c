/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:45:29 by humarque          #+#    #+#             */
/*   Updated: 2019/08/07 16:39:56 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			mouse_motion(int x, int y, t_fract *fract)
{
	if (fract->julia == 1)
	{
		fract->x2 = ((double)x - WIDTH / 2) / (double)(fract->zoom / 2);
		fract->y2 = ((double)y - HEIGHT / 2) / (double)(fract->zoom / 2);
	}
	make_draw(fract);
	return (0);
}

int			mouse_hook(int keycode, int x, int y, t_fract *fract)
{
	if (keycode == 4)
	{
		fract->zx = x - (fract->x1 / 2);
		fract->zy = y - (fract->y1 / 2);
		fract->x1 -= fract->zx;
		fract->y1 -= fract->zy;
		fract->zoom *= 1.5;
	}
	if (keycode == 5)
	{
		if (x < WIDTH && y < HEIGHT && y > 0)
		{
			fract->zx = x - (fract->x1 / 2);
			fract->zy = y - (fract->y1 / 2);
			fract->x1 += fract->zx;
			fract->y1 += fract->zy;
			fract->zoom /= 2;
		}
	}
	mlx_clear_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr);
	make_draw(fract);
	return (0);
}
