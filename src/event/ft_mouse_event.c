/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:19:50 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/23 09:19:14 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	ft_zoom(t_fractal *fractal, int x, int y, int zoom_in_out)
{
	double	zoom_level;
	double	*zoom;
	double	*offset_x;
	double	*offset_y;

	offset_y = &fractal->offset_y;
	offset_x = &fractal->offset_x;
	zoom = &fractal->zoom;
	if (zoom_in_out == 1)
	{
		zoom_level = *zoom * 1.42;
		*offset_x = (x / *zoom + *offset_x) - (x / zoom_level);
		*offset_y = (y / *zoom + *offset_y) - (y / zoom_level);
		*zoom = zoom_level;
	}
	else if (zoom_in_out == -1)
	{
		zoom_level = *zoom / 1.42;
		*offset_x = (x / *zoom + *offset_x) - (x / zoom_level);
		*offset_y = (y / *zoom + *offset_y) - (y / zoom_level);
		*zoom = zoom_level;
	}
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
