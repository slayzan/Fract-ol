/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:45:29 by humarque          #+#    #+#             */
/*   Updated: 2019/07/24 17:21:11 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

int		mouse_motion(int x, int y,	t_fract *fract)
{
	if (fract->julia == 1)
	{
		fract->x2 = ((double)x - WIDTH / 2) / (double)(fract->zoom / 2);
		fract->y2 = ((double)y - HEIGHT / 2) / (double)(fract->zoom / 2);
	}
	make_draw(fract);
	return (0);
}
