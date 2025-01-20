/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/20 13:10:45 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "mlx.h"
# include "X.h"

# define WIN_SIZE 1000
# define WINDOW_NAME "FRACT-OL"

//		accuracy
# define MAX_ITER 42

//		Key_press
# define ESC 65307
# define PLUS 65451
# define MINUS 65453
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define C 99
# define V 118
# define B 98
# define N 110

//		Mouse_hook
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define SCROLL_CLICK 2
# define LEFT_CLICK 1
# define RIGHT_CLICK 3

//		NAME FRACTAL
# define JULIA 1
# define MANDELBROT 2

typedef struct s_fractal
{
	double	z_real;
	double	z_imag;
	double	zoom;
	double	c_real;
	double	c_imag;
	double	offset_x;
	double	offset_y;
	int		accuracy;
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
	int			name;
	int			(*f)(struct s_data *, int, int);
	t_image		img;
	t_fractal	fractal;
}				t_data;

/*
 *		ft_param
*/
int		ft_param(int ac, char *p, t_data *data);

//		directorie event
/*
 *		ft_event
 */
int		ft_key_press(int keycode, void *param);
int		ft_mouse_hook(int mouse_code, int x, int y, t_data *data);

/*
 *		ft_is_keycode
*/
int		ft_is_arrow(int keycode);
int		ft_is_accuracy(int keycode);
int		ft_is_mv_base_point(int keycode, int name);
int		ft_is_one(int keycode, int name);

/*
 *		ft_julia_event
*/
void	ft_move_base_point(int keycode, t_fractal*f);

/*
 *		ft_close
*/
int		ft_cross(t_data *data);
int		ft_clean_close(t_data *data, int error);

/*
 *		ft_draw
*/
void	ft_color_pixel(int color, int x, int y, t_data *data);
int		ft_color(int iter, t_fractal *f);
void	ft_draw_fractal(t_data *data);
void	ft_who_draw(t_data *data);

/*
 *		ft_init
*/
int		ft_init(t_data *data);


/*
 *		fractal
*/
int		ft_mandelbrot(t_data *data, int x, int y);
int		ft_julia(t_data *data, int x, int y);

#endif
