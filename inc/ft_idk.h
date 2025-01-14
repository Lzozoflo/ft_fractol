/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idk.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/14 16:15:48 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IDK_H
# define FT_IDK_H

# include "mlx.h"
# include "mlx_int.h"

# define WIDTH 1080
# define HEIGHT 1080
# define NAME_WINDOW "OUI OUI"

#define MAX_ITER 10

// Key_press
# define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex
{
	double		imaginary;
	double		real;
}				t_complex;

// test
// void    fill_image(t_data *data, int width, int height, unsigned int color, int start);
void draw_mandelbrot(t_data *data);
// void draw_julia(t_data *data, double c_real, double c_imag);



//		ft_close
int		ft_cross_close(t_data *data);
int		ft_clean_close(t_data *data, int error);

//		ft_key_press
int		ft_key_press(int keycode, void *param);



#endif
