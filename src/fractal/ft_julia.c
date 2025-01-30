/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:01:21 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/30 09:59:47 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_julia(t_fractal f, int x, int y)
{
	double		tmp_real;
	int			iter;

	iter = -1;
	f.z_real = x *(f.zoom / WIN_SIZE) + f.offset_x;
	f.z_imag = -(y *(f.zoom / WIN_SIZE) - f.offset_y);
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
