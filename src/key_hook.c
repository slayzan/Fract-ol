/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:28:49 by humarque          #+#    #+#             */
/*   Updated: 2019/07/24 17:56:48 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"
int		key_hook(int keycode, t_fract *fract)
{
	if (keycode == 53)
		exit(0);
	ft_restart(keycode, fract);
	return(1);
}

void	ft_restart(int keycode, t_fract *fract)
{
	if (keycode == 35)
		ft_init(fract);
	else if (keycode == 18 || keycode == 83)
		fract->num = 1;
	else if (keycode == 19 || keycode 84)
		fract->num = 2;
}
