/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:31:48 by humarque          #+#    #+#             */
/*   Updated: 2019/06/20 17:40:29 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"
void	init_window(t_fract *fract)
{
	fract->mlx.mlx_ptr = mlx_init();
	fract->mlx.win_ptr = mlx_new_windows(fract->mlx.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	fract->mlx.img.img_ptr = mlx_new_image(fract->mlx.mlx_ptr, WIDTH,HEIGHT);
	fract->mlx.img.data = (int *)mlx_get_data_addr(fract->mlx.mlx_ptr, &param->graph.img.bpp, 
	&fract->mlx.img.size_l, &fract->mlx.img.endian);
	ft_init(fract);
	make_draw(fract);
	mlx_loop(fract->mlx.mlx_ptr);
}

void	ft_init(t_fract *fract)
{
	fract->itermax = 50;
	fract->x1 = WIDTH;
	fract->y1 = HEIGHT;
	fract->zoom = 100;
}


void	make_draw(t_fract *fract)
{
	fract->x = 0;
	while (fract->x < WIDTH)
	{
		fract->y = 0;
		while (fract->y < HEIGHT)
		{
			if (fract->num == 1)
				mandelbrot(fract);
			fract->y++;
		}
		fract->x++;
	}
	mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.mlx_window,fract->mlx.img.img_ptr, 0, 0);

}

int main(int argc,char **argv)
{
	t_fract fract;

	fract.num = 0;
	if (argc == 2)
	{
		if (ft_strcmp(argv[1],'1') == 0)
			fract->num = 1;
		if (fract.num)
			init_window(fract);
	}
/*	else
		ft_info();
		*/
}
