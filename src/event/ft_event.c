/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/20 13:11:58 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

static void	ft_accuracy(int keycode, t_fractal *f)
{
	if (keycode == PLUS)
		if (f->accuracy < 420)
			f->accuracy += 2;
	if (keycode == MINUS)
		if (f->accuracy > 12)
			f->accuracy -= 2;
}

static void	ft_arrow(int keycode, t_fractal *f)
{
	if (keycode == UP)
		f->offset_y += 4.2 / f->zoom;
	else if (keycode == DOWN)
		f->offset_y -= 4.2 / f->zoom;
	else if (keycode == LEFT)
		f->offset_x += 4.2 / f->zoom;
	else if (keycode == RIGHT)
		f->offset_x -= 4.2 / f->zoom;
}

int	ft_key_press(int keycode, void *param)
{
	t_fractal	*f;
	t_data		*data;

	data = (t_data *)param;
	f = &data->fractal;
	ft_printf("keycode : %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_loop_end(data->mlx);
		ft_clean_close(data, 0);
	}
	else if (ft_is_arrow(keycode))
		ft_arrow(keycode, &data->fractal);
	else if (ft_is_accuracy(keycode))
		ft_accuracy(keycode, &data->fractal);
	else if (ft_is_mv_base_point(keycode, data->name))
		ft_move_base_point(keycode, &data->fractal);
	if (ft_is_one(keycode, data->name))
		ft_who_draw(data);
	return (1);
}

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
		zoom_level = *zoom * 1.21;
		*offset_x = (x / *zoom + *offset_x) - (x / zoom_level);
		*offset_y = (y / *zoom + *offset_y) - (y / zoom_level);
		*zoom = zoom_level;
	}
	else if (zoom_in_out == -1)
	{
		zoom_level = *zoom / 1.21;
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
