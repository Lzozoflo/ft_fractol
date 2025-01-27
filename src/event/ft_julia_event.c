/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:26:20 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/27 15:56:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

void	ft_move_base_point(int keycode, t_fractal *f)
{
	if (keycode == C)
		f->c_real *= 1.25;
	else if (keycode == V)
		f->c_real *= 0.90;
	else if (keycode == B)
		f->c_imag *= 1.25;
	else if (keycode == N)
		f->c_imag *= 0.90;
}
