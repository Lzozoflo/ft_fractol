/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:27:43 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/17 14:45:05 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx.h"
# include "ft_fractol.h"
# include "libft.h"

// void    fill_image(t_data *data, int width, int height, unsigned int color, int start)
// {
// 	int x;
// 	int y;
// 	int index;

// 	for (y = start; y < height; y++)
// 	{
// 		for (x = start; x < width; x++)
// 		{
// 			index = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
// 			*(unsigned int *)(data->addr + index) = color;
// 		}
// 	}
// }
void	ft_color_pixel(int color, int x, int y, t_data *data)
{
	int	index;

	index = (y * data->img.line_len) + (x * (data->img.bpp / 8));
	*(unsigned int *)(data->img.addr + index) = color;
}



int	mandelbrot(double real, double imag)
{
	double z_real = 0.0;
	double z_imag = 0.0;
	int iter = 0;

	while (z_real * z_real + z_imag * z_imag <= 4.0 && iter < MAX_ITER)
	{
		double tmp_real = z_real * z_real - z_imag * z_imag + real;
		double tmp_imag = 2 * z_real * z_imag + imag;

		z_real = tmp_real;
		z_imag = tmp_imag;

		iter++;
	}
	return iter;
}

void ft_draw_mandelbrot(t_data *data)
{
	int	x,	y;
	double	real,	imag;
	int	color;


	double max_y = 3.0 / WIDTH;
	double max_x = 3.0 / HEIGHT;
	double min_y = -2.2;
	double min_x = -1.5;

	mlx_clear_window(data->mlx, data->win);
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			real = x * max_y + min_y;
			imag = y * max_x + min_x;

			int iter = mandelbrot(real, imag);

			if (iter == MAX_ITER)
				color = 0x000000;
			else
				color = (iter * 255) / MAX_ITER;

			ft_color_pixel(color, x, y, data);
		}
	}
}


// int julia(double real, double imag, double c_real, double c_imag)
// {
//     double z_real = real;
//     double z_imag = imag;
//     int iter = 0;

//     while (z_real * z_real + z_imag * z_imag <= 4.0 && iter < MAX_ITER)
//     {
//         double tmp_real = z_real * z_real - z_imag * z_imag + c_real;
//         double tmp_imag = 2 * z_real * z_imag + c_imag;

//         z_real = tmp_real;
//         z_imag = tmp_imag;

//         iter++;
//     }

//     return iter;
// }

// void draw_julia(t_data *data, double c_real, double c_imag)
// {
//     int x, y;
//     double real, imag;
//     int color;
// 	double zoom = 1.5; // Réduction du zoom (valeurs plus petites donnent plus de détails)
// 	double max_y = (3.0 / zoom) / WIDTH;
// 	double max_x = (3.0 / zoom) / HEIGHT;
// 	double min_y = -1.5 / zoom;
// 	double min_x = -1.5 / zoom;

//     for (y = 0; y < HEIGHT; y++)
//     {
//         for (x = 0; x < WIDTH; x++)
//         {
//             real = x * max_y + min_y;
//             imag = y * max_x + min_x;

//             int iter = julia(real, imag, c_real, c_imag);

//             // Calcul de la couleur (basé sur le nombre d'itérations)
//             if (iter == MAX_ITER)
//                 color = 0x000000; // Noir (partie de l'ensemble de Julia)
//             else
//                 color = (iter * 255) / MAX_ITER;

//             // Utilisation de mlx pour dessiner le pixel
//             int index = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
//             *(unsigned int *)(data->addr + index) = color;
//         }
//     }
// }
