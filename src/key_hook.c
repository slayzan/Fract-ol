/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:28:49 by humarque          #+#    #+#             */
/*   Updated: 2019/08/07 17:08:19 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			key_hook(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	iter_color(keycode, fract);
	ft_restart(keycode, fract);
	ft_move(keycode, fract);
	return (1);
}

void		iter_color(int keycode, t_fract *fract)
{
	if (keycode == 69 || keycode == 24)
		fract->itermax += 5;
	else if ((keycode == 27 || keycode == 78) && (fract->itermax > 5))
		fract->itermax -= 5;
	else if (keycode == 15)
	{
		fract->color.r = fract->color.r - 255;
		fract->color.r = fract->color.r == 255 ? 0 : fract->color.r;
	}
	else if (keycode == 5)
	{
		fract->color.g = fract->color.g - 255;
		fract->color.g = fract->color.g == 255 ? 0 : fract->color.g;
	}
	else if (keycode == 11)
	{
		fract->color.b = fract->color.b - 255;
		fract->color.b = fract->color.b == 255 ? 0 : fract->color.b;
	}
	mlx_clear_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr);
	make_draw(fract);
}

void		ft_restart(int keycode, t_fract *fract)
{
	if ((keycode == 35) || (keycode == 18 || keycode == 83)
			|| (keycode == 19 || keycode == 84))
	{
		if (keycode == 35)
			ft_init(fract);
		else if (keycode == 18 || keycode == 83)
			fract->num = 1;
		else if (keycode == 19 || keycode == 84)
			fract->num = 2;
		ft_init(fract);
		if (keycode == 75 && fract->color.depth >= 2)
		{
			fract->color.depth--;
			fract->color.depth = fract->color.depth
				== 0 ? 255 : fract->color.depth;
		}
		else if (keycode == 67 && fract->color.depth <= 100)
		{
			fract->color.depth++;
			fract->color.depth = fract->color.depth
				== 0 ? 255 : fract->color.depth;
		}
		mlx_clear_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr);
		make_draw(fract);
	}
}

void		ft_move(int keycode, t_fract *fract)
{
	if (keycode == 126)
		fract->y1 -= 100;
	else if (keycode == 125)
		fract->y1 += 100;
	else if (keycode == 123)
		fract->x1 -= 100;
	else if (keycode == 124)
		fract->x1 += 100;
	else if (keycode == 49)
		fract->julia = fract->julia == 1 ? 0 : 1;
	mlx_clear_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr);
	make_draw(fract);
}
