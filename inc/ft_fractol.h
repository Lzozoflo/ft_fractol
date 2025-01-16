/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/16 18:23:44 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IDK_H
# define FT_IDK_H

# include "mlx.h"
# include "X.h"

# define WIDTH 1000
# define HEIGHT 1000
# define WINDOW_NAME "OUI OUI"

# define MAX_ITER 256

// Key_press
# define ESC 65307
# define PLUS 65451
# define MINUS 65453
// # define ESC 65307
// # define ESC 65307
// # define ESC 65307

typedef struct s_complex
{
	double		imag;
	double		real;
}				t_complex;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_fractal
{
	double	zoom;
	double	scale_real;
	double	scale_imag;
	double	offset_real;
	double	offset_imag;
}				t_fractal;

typedef struct s_image
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_fractal	fractal;
}				t_data;


// test
// void    fill_image(t_data *data, int width, int height, unsigned int color, int start);
void	ft_draw_mandelbrot(t_data *data);
// void draw_julia(t_data *data, double c_real, double c_imag);



//		ft_close
int		ft_cross_close(t_data *data);
int		ft_clean_close(t_data *data, int error);

//		ft_key_press
int		ft_key_press(int keycode, void *param);



#endif
