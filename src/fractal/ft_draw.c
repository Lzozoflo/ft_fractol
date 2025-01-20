/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:39:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/20 12:54:17 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_color_pixel(int color, int x, int y, t_data *data)
{
	t_image	img;
	int		index;

	img = data->img;
	index = (y * img.line_len) + (x * (data->img.bpp));
	*(unsigned int *)(data->img.addr + index) = color;
}

// (r % 256, 0, 0)
// int (r, g, b) {
// 	return (r << 16 | g << 8 | b )
// }

int	ft_color(int iter, t_fractal *f)
{
	if (iter == f->accuracy)
		return (0x000000);
	else
		return ((iter * 255) / 8);
}

void	ft_draw_fractal(t_data *data)
{
	int	color;
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			color = data->f(data, x, y);
			ft_color_pixel(color, x, y, data);
		}
	}
}

void	ft_who_draw(t_data *data)
{
	if (data->name == MANDELBROT)
		data->f = ft_mandelbrot;
	else if (data->name == JULIA)
		data->f = ft_julia;
	ft_draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
