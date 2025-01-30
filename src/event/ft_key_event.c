/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/30 10:56:51 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

static void	ft_zoom(double *zoom, double *set_x, double *set_y, int in_out)
{
	double	zoom_factor;
	double	mouse_x;
	double	mouse_y;
	int		center;

	zoom_factor = 1.042;
	center = (WIN_SIZE >> 1);
	mouse_x = (double)center * (*zoom / WIN_SIZE) + *set_x;
	mouse_y = -((double)center * (*zoom / WIN_SIZE) - *set_y);
	if (in_out == 1)
	{
		*zoom /= zoom_factor;
	}
	else if (in_out == -1)
	{
		*zoom *= zoom_factor;
	}
	*set_x = mouse_x - (center * (*zoom / WIN_SIZE));
	*set_y = mouse_y + (center * (*zoom / WIN_SIZE));
}

static void	ft_accuracy(int keycode, int *accuracy)
{
	if (keycode == NUM_PAD_PLUS)
	{
		if (*accuracy < 420)
			*accuracy += 8;
	}
	else if (keycode == NUM_PAD_MINUS)
	{
		if (*accuracy > 12)
			*accuracy -= 4;
	}
	else if (keycode == NUM_PAD_ENTER)
		*accuracy = MAX_ITER;
}

static void	ft_arrow(int keycode, t_fractal *f)
{
	if (keycode == UP)
		f->offset_y += 0.042;
	else if (keycode == DOWN)
		f->offset_y -= 0.042;
	else if (keycode == RIGHT)
		f->offset_x += 0.042;
	else if (keycode == LEFT)
		f->offset_x -= 0.042 ;
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
		ft_arrow(keycode, f);
	else if (ft_is_accuracy_key(keycode))
		ft_accuracy(keycode, &f->accuracy);
	else if (ft_is_mv_base_point_key(keycode, data->name))
		ft_move_base_point(keycode, f);
	else if (ft_is_rbg_key(keycode))
		ft_change_base_value_rgb(keycode, &data->rgb);
	else if (keycode == PLUS)
		ft_zoom(&f->zoom, &f->offset_x, &f->offset_y, 1);
	else if (keycode == MINUS)
		ft_zoom(&f->zoom, &f->offset_x, &f->offset_y, -1);
	if (ft_is_one_key(keycode, data->name))
		ft_who_draw(data);
	return (1);
}
