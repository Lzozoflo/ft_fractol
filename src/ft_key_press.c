/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/16 17:52:56 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

int	ft_key_press(int keycode, void *param)
{
	t_data	*data;

	ft_printf("keycode : %d\n", keycode);
	data = (t_data *)param;
	if (keycode == ESC)
	{
		mlx_loop_end(data->mlx);
		ft_clean_close(data, 0);
	}
	else if (keycode == PLUS)
	{
		data->fractal.zoom += 0.05;
		ft_draw_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	}
	else if (keycode == MINUS)
	{
		data->fractal.zoom -= 0.05;
		ft_draw_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	}
	// else if (keycode == ESC)
	// {
	// 	mlx_loop_end(data->mlx);
	// 	ft_clean_close(data, 0);
	// }
	return (1);
}




// int handle_keypress(int keycode, void *param)
// {
// 	t_data *data = (t_data *)param;
// 	static int x = 450;
// 	static int y = 900;
// 	static int i = 100;

// 	printf("key pressed! : %d\n", keycode);
// 	if (keycode == 65439 || keycode == 46)//.
// 	{
// 		draw_circle(data, y, x, i, 0x0000FF00);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 		i += 5;
// 	}
// 	if (keycode == 65451)//+
// 	{
// 		draw_circle(data, y, x, i, 0x00000000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 		i += 50;
// 		draw_circle(data, y, x, i, 0x0000FF00);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 	}
// 	if (keycode == 65453)//-
// 	{
// 		draw_circle(data, y, x, i, 0x00000000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 		i -= 5;
// 		draw_circle(data, y, x, i, 0x0000FF00);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 	}
// 	if (keycode == 65361)
// 	{
// 		draw_circle(data, y, x, i, 0x00000000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 		y -= 5;
// 		draw_circle(data, y, x, i, 0x0000FF00);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 	}
// 	if (keycode == 65363)
// 	{
// 		draw_circle(data, y, x, i, 0x00000000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);

// 		y += 5;
// 		draw_circle(data, y, x, i, 0x0000F000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 	}
// 	if (keycode == 65362)
// 	{
// 		draw_circle(data, y, x, i, 0x00000000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 		// i += 5;
// 		x -= 5;
// 		draw_circle(data, y, x, i, 0x000000FF);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 	}
// 	if (keycode == 65364)
// 	{
// 		draw_circle(data, y, x, i, 0x00000000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 		// i += 5;
// 		x += 5;
// 		draw_circle(data, y, x, i, 0x00FF0000);
// 		mlx_put_image_to_window(data->mlx, data->win, data->img, 50, 50);
// 	}
// 	if (keycode == 65307)
// 	{
// 		mlx_loop_end(data->mlx);
// 		clean_exit(data);
// 	}
// 	return (0);
// }
