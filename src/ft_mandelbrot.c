/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:18:07 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/16 19:00:06 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

void	ft_color_pixel(int color, int x, int y, t_data *data)
{
	int	index;

	index = (y * data->img.line_len) + (x * (data->img.bpp / 8));
	*(unsigned int *)(data->img.addr + index) = color;
}

int	ft_mandelbrot(t_complex *c)
{
	t_complex	z;
	double		tmp_real;
	int			iter;

	iter = 0;
	z.real = 0.0;
	z.imag = 0.0;
	while ((z.real * z.real) + (z.imag * z.imag) <= 4.0 && ++iter < MAX_ITER)
	{
		tmp_real = (z.real * z.real) - (z.imag * z.imag) + c->real;
		z.imag = 2 * z.real * z.imag + c->imag;
		z.real = tmp_real;
	}
	return (iter);
}

void	ft_draw_mandelbrot(t_data *data)
{
	t_complex	c;
	t_fractal	*f;
	t_pos		p;
	int			color;
	int			iter;

	f = &data->fractal;
	// double scale_real = 3.0 / WIDTH;
	// double scale_imag = 3.0 / HEIGHT;
	// double offset_real = -2;
	// double offset_imag = -1.5;



	f->offset_imag = -1.5 ; // y
	f->offset_real = -1.5 ; // x
	f->scale_imag = 2.0 / HEIGHT;
	f->scale_real = 2.0 / WIDTH;
	p.y = -1;
	while (++p.y < HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
		{
			// c.real = x * (scale_real / f->zoom) + offset_real;
			// c.imag = y * (scale_imag / f->zoom) + offset_imag;
			c.imag = p.y * (f->scale_imag / f->zoom)+ f->offset_imag;
			c.real = p.x * (f->scale_real / f->zoom) + f->offset_real;

			iter = ft_mandelbrot(&c);

			if (iter == MAX_ITER)
				color = 0x000000;
			else
				color = (iter * 255) / MAX_ITER;

			ft_color_pixel(color, p.x, p.y, data);
		}
	}
}

