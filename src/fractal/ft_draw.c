/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:39:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/21 21:36:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	ft_color_pixel(int color, int x, int y, t_data *data)
{
	t_image	img;
	int		index;

	img = data->img;
	index = (y * img.line_len) + (x * (data->img.bpp));
	*(unsigned int *)(data->img.addr + index) = color;
}

static int	ft_color(int iter, t_fractal f, t_rgb rgb)
{
	int	r;
	int	g;
	int	b;

	if (iter == f.accuracy)
		return (0x000000);
	r = (iter * rgb.red) % 256;
	g = (iter * rgb.greed) % 256;
	b = (iter * rgb.blue) % 256;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_draw_fractal(t_data *data, int (*f)(t_fractal, int, int))
{
	t_fractal	fractal;
	t_rgb		rgb;
	int			color;
	int			x;
	int			y;

	y = -1;
	rgb = data->rgb;
	fractal = data->fractal;
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			color = ft_color(f(fractal, x, y), fractal, rgb);
			ft_color_pixel(color, x, y, data);
		}
	}
}

void	ft_who_draw(t_data *data)
{
	if (data->name == MANDELBROT)
		ft_draw_fractal(data, ft_mandelbrot);
	else if (data->name == JULIA || data->name == JULIA_WITH_PARAM)
		ft_draw_fractal(data, ft_julia);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
