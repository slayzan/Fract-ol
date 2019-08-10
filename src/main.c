/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:32:55 by humarque          #+#    #+#             */
/*   Updated: 2019/08/10 15:18:20 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		ft_init(t_fract *fract)
{
	fract->julia = 1;
	fract->itermax = 50;
	fract->x1 = WIDTH;
	fract->y1 = HEIGHT;
	fract->zoom = 300;
	fract->color.r = 255;
	fract->color.b = 255;
	fract->color.g = 255;
	fract->color.depth = 1;
}

void		make_draw(t_fract *fract)
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
			else if (fract->num == 3)
				ft_burningship(fract);
			fract->y++;
		}
		fract->x++;
	}
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
			fract->mlx.win_ptr, fract->mlx.img.img_ptr, 0, 0);
}

void		ft_mlx(t_fract *fract)
{
	fract->mlx.mlx_ptr = mlx_init();
	fract->mlx.win_ptr = mlx_new_window(fract->mlx.mlx_ptr,
			WIDTH, HEIGHT, "Fractol");
	fract->mlx.img.img_ptr = mlx_new_image(fract->mlx.mlx_ptr,
			WIDTH, HEIGHT);
	fract->mlx.img.data = mlx_get_data_addr(fract->mlx.img.img_ptr,
			&fract->mlx.img.bpp, &fract->mlx.img.size_l,
			&fract->mlx.img.endian);
	ft_init(fract);
	make_draw(fract);
	mlx_hook(fract->mlx.win_ptr, 2, 0, key_hook, fract);
	mlx_hook(fract->mlx.win_ptr, 4, 0, mouse_hook, fract);
	mlx_hook(fract->mlx.win_ptr, 6, 0, mouse_motion, fract);
	mlx_loop(fract->mlx.mlx_ptr);
}

void	ft_print_error()
{
	ft_putendl("usage: ./fractol <number>");
    ft_putendl("1 = Mandelbrot");
    ft_putendl("2 = Julia");
    ft_putendl("3 = Burningship");	
}

int			main(int argc, char **argv)
{
	t_fract fract;

	fract.num = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "1") == 0)
			fract.num = 1;
		else if (ft_strcmp(argv[1], "2") == 0)
			fract.num = 2;
		else if (ft_strcmp(argv[1], "3") == 0)
			fract.num = 3;
		if (fract.num < 4)
			ft_mlx(&fract);
	}
	else
		ft_print_error();
}
