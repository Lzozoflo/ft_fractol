/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:18:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/22 19:21:07 by fcretin          ###   ########.fr       */
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
	double		tmp_imag;
	int			iter;

	iter = -1;
	f.z_real = 0.0;
	f.z_imag = 0.0;
	f.c_real = (x / f.zoom) + f.offset_x;
	f.c_imag = (y / f.zoom) + f.offset_y;
	while (++iter < f.accuracy)
	{
		tmp_real = (ft_fabs(f.z_real) * ft_fabs(f.z_real))
			- (ft_fabs(f.z_imag) * ft_fabs(f.z_imag)) + f.c_real;
		tmp_imag = (2 * ft_fabs(f.z_real) * ft_fabs(f.z_imag)) + f.c_imag;
		f.z_real = tmp_real;
		f.z_imag = tmp_imag;
		if ((f.z_real * f.z_real) + (f.z_imag * f.z_imag) >= 4)
			break ;
	}
	return (iter);
}
