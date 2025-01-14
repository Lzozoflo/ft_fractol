/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/14 14:11:53 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_idk.h"

void	ft_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, NAME_WINDOW);
	if (!data->win)
		ft_clean_close(data, 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_clean_close(data, 1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}



int	main(void)
{
	t_data	data;
	double c_real = -0.70176;
	double c_imag = 0.3842;
	ft_init(&data);

	// fill_image(&data, WIDTH, HEIGHT , 0x000000FF, 0); // Rouge
	// fill_image(&data, WIDTH- 100 , HEIGHT - 100, 0x00FF0000, 50); // Rouge

	draw_mandelbrot(&data);
	// draw_julia(&data, c_real, c_imag);

	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);



	mlx_hook(data.win, KeyPress, KeyPressMask, ft_key_press, &data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, ft_cross_close, &data);
	mlx_loop(data.mlx);
}
