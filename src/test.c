/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:27:43 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/14 16:16:08 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx.h"
# include "ft_idk.h"

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


int mandelbrot(double real, double imag)
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

void draw_mandelbrot(t_data *data)
{
	int	x,	y;
	double	real,	imag;
	int	color;
	double zoom = 1;
	double scale_real = (3.0 / zoom) / WIDTH;
	double scale_imag = (3.0 / zoom) / HEIGHT;
	double offset_real = -1.5 / zoom;
	double offset_imag = -1.5 / zoom;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			real = x * scale_real + offset_real;
			imag = y * scale_imag + offset_imag;

			int iter = mandelbrot(real, imag);

			// Calcul de la couleur (basé sur le nombre d'itérations)
			if (iter == MAX_ITER)
				color = 0x000000; // Noir (partie de l'ensemble de Mandelbrot)
			else
				color = (iter * 255) / MAX_ITER;

			// Utilisation de mlx pour dessiner le pixel
			int index = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
			*(unsigned int *)(data->addr + index) = color;
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
// 	double scale_real = (3.0 / zoom) / WIDTH;
// 	double scale_imag = (3.0 / zoom) / HEIGHT;
// 	double offset_real = -1.5 / zoom;
// 	double offset_imag = -1.5 / zoom;

//     for (y = 0; y < HEIGHT; y++)
//     {
//         for (x = 0; x < WIDTH; x++)
//         {
//             real = x * scale_real + offset_real;
//             imag = y * scale_imag + offset_imag;

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
