/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:51:58 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/20 08:59:50 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdlib.h>

static void	ft_hook_event(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_mouse_hook(data->win, ft_mouse_hook, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_cross, data);
}

static void	ft_fractol_init(t_fractal *f)
{
	f->zoom = 300;
	f->offset_x = -1.75;
	f->offset_y = -1.75;
	f->c_imag = -0.50;
	f->c_real = -0.05;
	f->accuracy = MAX_ITER;
}

// static void	ft_julia_init(t_fractal *f)
// {
// 	f->zoom = 300;
// 	f->offset_x = -2.0;
// 	f->offset_y = -2.0;
// 	f->c_imag = -0.7454;
// 	f->c_real = -0.04;
// 	f->accuracy = MAX_ITER;
// }

int	ft_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIN_SIZE, WIN_SIZE, WINDOW_NAME);
	if (!data->win)
		ft_clean_close(data, 1);
	data->img.img_ptr = mlx_new_image(data->mlx, WIN_SIZE, WIN_SIZE);
	if (!data->img.img_ptr)
		ft_clean_close(data, 1);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.bpp /= 8;
	// if (ft_is_julia(data))
	// ft_julia_init(&data->fractal);
	// else
	ft_fractol_init(&data->fractal);
	ft_hook_event(data);
	return (1);
}
