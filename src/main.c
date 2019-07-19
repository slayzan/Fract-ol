/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:22:26 by humarque          #+#    #+#             */
/*   Updated: 2019/07/19 16:07:47 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

void	ft_init(t_fract *fract)
{
	fract->itermax = 40;
	fract->x1 = WIDTH;
	fract->y1 = HEIGHT;
	fract->zoom = 300;
	fract->color.r = 255;
	fract->color.b = 255;
	fract->color.g = 255;
	fract->color.depth = 1;
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
			else if (fract->num == 2)
				ft_julia(fract);
			fract->y++;
		}
		fract->x++;
	}
	mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.win_ptr, fract->mlx.img.img_ptr, 0, 0);
 
}

void	ft_mlx(t_fract *fract)
{
	fract->mlx.mlx_ptr = mlx_init();
	fract->mlx.win_ptr = mlx_new_window(fract->mlx.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	fract->mlx.img.img_ptr = mlx_new_image(fract->mlx.mlx_ptr, WIDTH, HEIGHT);
   fract->mlx.img.data = mlx_get_data_addr(fract->mlx.img.img_ptr, &fract->mlx.img.bpp, &fract->mlx.img.size_l, &fract->mlx.img.endian);
   ft_init(fract);
   make_draw(fract);
mlx_loop(fract->mlx.mlx_ptr);   
}


int main	(int argc, char **argv)
{
	t_fract fract;

	fract.num = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "1") == 0)
			fract.num = 1;
		else if (ft_strcmp(argv[2], "2") == 0)
			fract.num = 2;
		if (fract.num < 5)
			ft_mlx(&fract);
	}
	else
		printf("no");
}
