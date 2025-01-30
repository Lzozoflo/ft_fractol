/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:19:50 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/30 09:54:33 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	ft_zoom(t_fractal *fractal, int x, int y, int in_out)
{
	double	zoom_factor;
	double	mouse_x;
	double	mouse_y;
	double	*set_x;
	double	*set_y;

	set_x = &fractal->offset_x;
	set_y = &fractal->offset_y;
	zoom_factor = 1.42;
	mouse_x = (double)x * (fractal->zoom / WIN_SIZE) + *set_x;
	mouse_y = -((double)y * (fractal->zoom / WIN_SIZE) - *set_y);
	if (in_out == 1)
	{
		fractal->zoom /= zoom_factor;
	}
	else if (in_out == -1)
	{
		fractal->zoom *= zoom_factor;
	}
	*set_x = mouse_x - (x * (fractal->zoom / WIN_SIZE));
	*set_y = mouse_y + (y * (fractal->zoom / WIN_SIZE));
}

int	ft_mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == SCROLL_DOWN || mouse_code == LEFT_CLICK)
		ft_zoom(&data->fractal, x, y, 1);
	else if (mouse_code == SCROLL_UP || mouse_code == RIGHT_CLICK)
		ft_zoom(&data->fractal, x, y, -1);
	if (mouse_code != SCROLL_CLICK)
		ft_who_draw(data);
	return (0);
}
