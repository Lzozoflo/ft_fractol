/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:18:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/30 10:13:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	ft_burning_ship(t_fractal f, int x, int y)
{
	double		tmp_real;
	int			iter;

	iter = -1;
	f.z_real = 0.0;
	f.z_imag = 0.0;
	f.c_real = x * (f.zoom / WIN_SIZE) + f.offset_x;
	f.c_imag = y * (f.zoom / WIN_SIZE) - f.offset_y;
	while (++iter < f.accuracy)
	{
		tmp_real = (f.z_real * f.z_real) - (f.z_imag * f.z_imag) + f.c_real;
		f.z_imag = 2 * ft_fabs(f.z_real * f.z_imag) + f.c_imag;
		f.z_real = ft_fabs(tmp_real);
		if ((f.z_real * f.z_real) + (f.z_imag * f.z_imag) >= 4)
			break ;
	}
	return (iter);
}
