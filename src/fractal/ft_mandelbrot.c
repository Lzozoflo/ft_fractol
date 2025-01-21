/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:18:07 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/21 12:22:50 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

int	ft_mandelbrot(t_fractal	f, int x, int y)
{
	double		tmp_real;
	int			iter;

	iter = -1;
	f.z_real = 0.0;
	f.z_imag = 0.0;
	f.c_real = (x / f.zoom) + f.offset_x;
	f.c_imag = (y / f.zoom) + f.offset_y;
	while (++iter < f.accuracy)
	{
		tmp_real = (f.z_real * f.z_real) - (f.z_imag * f.z_imag) + f.c_real;
		f.z_imag = 2 * f.z_real * f.z_imag + f.c_imag;
		f.z_real = tmp_real;
		if ((f.z_real * f.z_real) + (f.z_imag * f.z_imag) >= 4)
			break ;
	}
	return (iter);
}
