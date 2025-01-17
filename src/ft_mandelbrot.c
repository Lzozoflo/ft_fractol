/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:18:07 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/17 14:56:19 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

void	ft_color_pixel(int color, int x, int y, t_data *data)
{
	t_image	img;
	int		index;

	img = data->img;
	index = (y * img.line_len) + (x * (data->img.bpp));
	*(unsigned int *)(data->img.addr + index) = color;
}

int	ft_color(int iter)
{
	int	color;

	if (iter == MAX_ITER)
		return (color = 0x000000);
	else
		return (color = (iter * 255) >> 6);
	return (0x000000);
}

int	ft_mandelbrot(t_complex *c)
{
	double	real;
	double	imag;
	double	tmp_real;
	int		iter;

	iter = -1;
	real = 0.0;
	imag = 0.0;
	while ((real * real) + (imag * imag) <= 4.0 && ++iter < MAX_ITER)
	{
		tmp_real = (real * real) - (imag * imag) + c->real;
		imag = 2 * real * imag + c->imag;
		real = tmp_real;
	}
	return (ft_color(iter));
}

void	ft_opti(t_fractal *f)
{
	f->scale_imag /= f->zoom;
	f->offset_imag /= f->zoom;
	f->scale_real /= f->zoom;
	f->offset_real /= f->zoom;
}

void	ft_draw_mandelbrot(t_data *data)
{
	t_complex	c;
	t_fractal	f;
	int			color;
	int			y;
	int			x;

	y = -1;
	f = data->fractal;
	ft_opti(&f);
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			c.real = x * f.scale_real + f.offset_real;
			c.imag = y * f.scale_imag + f.offset_imag;
			color = ft_mandelbrot(&c);
			ft_color_pixel(color, x, y, data);
		}
	}
}

void	ft_draw(t_data *data)
{
	ft_draw_mandelbrot(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
