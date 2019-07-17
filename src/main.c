/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:22:26 by humarque          #+#    #+#             */
/*   Updated: 2019/07/17 19:26:59 by humarque         ###   ########.fr       */
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


void	ft_mlx(t_fract *fract)
{
	fract->graph.mlx_ptr = mlx_init();
	fract->graph.mlx_window = mlx_new_window(fract->graph.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	fract->graph.img.img_ptr = mlx_new_image(fract->graph.mlx_ptr, WIDTH, HEIGHT);
   fract->graph.img.data = mlx_get_data_addr(fract->graph.img.img_ptr, &param->grap.img.bpp, &param->graph.img.size_l, &param->graph.img.endian);
   ft_init(fract);
   make_draw(fract);
mlx_loop(fract->graph.mlx_ptr);   
}

void	make_draw(t_fract *fract)
{
	
}



int main	(int argc, char **argv)
{
	t_fract fract;

	fract.num = 0;
	if (argc > 1)
	{
		if (strcmp(argv[1], "1") == 0)
			fract.num = 1;
		else if (strcmp(argv[2], "2") == 0)
			fract.num = 2;
		if (fract.num < 5)
			ft_mlx(&fract)
	}
	else
		printf("no");
}
