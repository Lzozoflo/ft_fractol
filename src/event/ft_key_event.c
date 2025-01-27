/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/27 16:08:55 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

static void	ft_zoom(t_fractal *fractal, int zoom_in_out)
{
	double	zoom_level;
	double	*zoom;
	double	*offset_x;
	double	*offset_y;
	int		center;

	offset_y = &fractal->offset_y;
	offset_x = &fractal->offset_x;
	zoom = &fractal->zoom;
	center = (WIN_SIZE >> 1);
	if (zoom_in_out == 1)
	{
		zoom_level = *zoom * 1.42;
		*offset_x = (center / *zoom + *offset_x) - (center / zoom_level);
		*offset_y = (center / *zoom + *offset_y) - (center / zoom_level);
		*zoom = zoom_level;
	}
	else if (zoom_in_out == -1)
	{
		zoom_level = *zoom / 1.42;
		*offset_x = (center / *zoom + *offset_x) - (center / zoom_level);
		*offset_y = (center / *zoom + *offset_y) - (center / zoom_level);
		*zoom = zoom_level;
	}
	fractal->accuracy = MAX_ITER;
}

static void	ft_accuracy(int keycode, t_fractal *f)
{
	if (keycode == NUM_PAD_PLUS)
	{
		if (f->accuracy < 420)
			f->accuracy += 8;
	}
	else if (keycode == NUM_PAD_MINUS)
	{
		if (f->accuracy > 12)
			f->accuracy -= 4;
	}
	else if (keycode == NUM_PAD_ENTER)
		f->accuracy = MAX_ITER;
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

static void	ft_change_base_value_rgb(int keycode, t_rgb *rgb)
{
	if (keycode == NUM_PAD_4)
		rgb->red += 2;
	else if (keycode == NUM_PAD_1)
		rgb->red -= 2;
	else if (keycode == NUM_PAD_5)
		rgb->green += 2;
	else if (keycode == NUM_PAD_2)
		rgb->green -= 2;
	else if (keycode == NUM_PAD_6)
		rgb->blue += 2;
	else if (keycode == NUM_PAD_3)
		rgb->blue -= 2;
}

int	ft_key_press(int keycode, void *param)
{
	t_fractal	*f;
	t_data		*data;

	data = (t_data *)param;
	f = &data->fractal;
	if (keycode == ESC)
	{
		mlx_loop_end(data->mlx);
		ft_clean_close(data, 0);
	}
	else if (ft_is_arrow_key(keycode))
		ft_arrow(keycode, &data->fractal);
	else if (ft_is_accuracy_key(keycode))
		ft_accuracy(keycode, &data->fractal);
	else if (ft_is_mv_base_point_key(keycode, data->name))
		ft_move_base_point(keycode, &data->fractal);
	else if (ft_is_rbg_key(keycode))
		ft_change_base_value_rgb(keycode, &data->rgb);
	else if (keycode == PLUS)
		ft_zoom(f, 1);
	else if (keycode == MINUS)
		ft_zoom(f, -1);
	if (ft_is_one_key(keycode, data->name))
		ft_who_draw(data);
	return (1);
}
