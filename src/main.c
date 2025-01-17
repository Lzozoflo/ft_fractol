/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/17 14:56:09 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdlib.h>

void	ft_event(t_data *data)
{
	//touche clavier
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_key_press, data);
	// //mouse buttom
	// mlx_hook(data->win, ButtonPress, ButtonPressMask, ft_key_press, &data);
	//la croix trouve pour fermer
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_cross, data);
}

void	ft_fractol_init(t_fractal *f)
{
	f->zoom = 1;
	f->offset_real = -2.2 ; // x
	f->scale_real = 3.0 / WIN_SIZE;
	f->offset_imag = -1.5 ; // y
	f->scale_imag = 3.0 / WIN_SIZE;
}

void	ft_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, WIN_SIZE, WIN_SIZE, WINDOW_NAME);
	if (!data->win)
		ft_clean_close(data, 1);
	data->img.img_ptr = mlx_new_image(data->mlx, WIN_SIZE, WIN_SIZE);
	if (!data->img.img_ptr)
		ft_clean_close(data, 1);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.bpp /= 8;
	ft_fractol_init(&data->fractal);
	ft_event(data);
}

int	main(void)
{
	t_data	data;

	ft_init(&data);
	ft_draw(&data);

	// mlx_hook(data.win, KeyPress, KeyPressMask, ft_key_press, &data);
	mlx_loop(data.mlx);
}
