/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:24:15 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/30 11:33:03 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

static int	ft_help_key(void)
{
	ft_printf("+-----------------------------------------------------+\n");
	ft_printf("|                                                     |\n");
	ft_printf("|   Quit                : ESC                         |\n");
	ft_printf("|                                                     |\n");
	ft_printf("|   Arrow for moving    : UP, DOWN, LEFT, RIGHT       |\n");
	ft_printf("|                                                     |\n");
	ft_printf("|  Zoom in (on target)  : LEFT_CLICK, SCROLL_UP, +    |\n");
	ft_printf("|  Zoom out (on target) : RIGHT_CLICK, SCROLL_DOWN, - |\n");
	ft_printf("|                                                     |\n");
	ft_printf("|   Details             : num_pad_+, num_pad_-        |\n");
	ft_printf("|   Reset details       : num_pad_enter               |\n");
	ft_printf("|                                                     |\n");
	ft_printf("|   Change color        :                             |\n");
	ft_printf("|    *     RED   = num_pad_4 = +,   num_pad_1 = -     |\n");
	ft_printf("|    *     GREEN = num_pad_5 = +,   num_pad_2 = -     |\n");
	ft_printf("|    *     BLUE  = num_pad_6 = +,   num_pad_3 = -     |\n");
	ft_printf("|                                                     |\n");
	ft_printf("|   Julia only          :                             |\n");
	ft_printf("|    *        C (real++), V (real--)                  |\n");
	ft_printf("|    *        B (imag++), N (imag--)                  |\n");
	ft_printf("|                                                     |\n");
	ft_printf("+-----------------------------------------------------+\n");
	return (0);
}

static int	ft_help_param(int error)
{
	if (error == -1)
	{
		ft_printf("+-----------------------------------------------------+\n");
		ft_printf("|                                                     |\n");
		ft_printf("|   Empty Param ---> ./fractol <param>                |\n");
		ft_printf("|                                                     |\n");
		ft_printf("|   Setting Key : --Help_key, -H                      |\n");
		ft_printf("|                                                     |\n");
		ft_printf("|   Fractal Param Available :                         |\n");
		ft_printf("|   --Mandelbrot, -M                                  |\n");
		ft_printf("|   --Julia, -J  >>     <-/+1.123>     <-/+1.123>     |\n");
		ft_printf("|   --Burning_ship, -B                                |\n");
		ft_printf("|                                                     |\n");
		ft_printf("|   Exemple : ./fractol --Julia 0.285  0.013          |\n");
		ft_printf("|                                                     |\n");
		ft_printf("+-----------------------------------------------------+\n");
		return (0);
	}
	return (1);
}

static int	ft_julia_param(t_data *data, char **param)
{
	double	param1;
	double	param2;
	int		i_cap;
	int		f_cap;

	i_cap = 1;
	f_cap = 3;
	if (!(ft_digit_sign_float(param[2]) && ft_digit_sign_float(param[3])))
		return (-1);
	param1 = ft_atod(param[2]);
	i_cap = 1;
	f_cap = 3;
	param2 = ft_atod(param[3]);
	data->fractal.c_real = param1;
	data->fractal.c_imag = param2;
	data->name = JULIA_WITH_PARAM;
	return (1);
}

static int	ft_is_mandelbrot_buring_ship(int *name, char **param)
{
	if (!ft_strncmp(param[1], "--Mandelbrot", 12)
		|| !ft_strncmp(param[1], "-M", 2))
	{
		*name = MANDELBROT;
		return (1);
	}
	else if (!ft_strncmp(param[1], "--Burning_ship", 14)
		|| !ft_strncmp(param[1], "-B", 2))
	{
		*name = BURNING_SHIP;
		return (1);
	}
	return (0);
}

int	ft_param(int ac, char **param, t_data *data)
{
	if (ac == 1)
		return (ft_help_param(-1));
	else if (ft_strncmp(param[1], "--Help_key", 10) == 0
		|| ft_strncmp(param[1], "-H", 2) == 0)
		return (ft_help_key());
	else if (ac == 2 && ((ft_strncmp(param[1], "--Julia", 7) == 0) \
		|| (ft_strncmp(param[1], "-J", 2) == 0)))
	{
		data->name = JULIA;
		return (1);
	}
	else if (!ft_strncmp(param[1], "--Mandelbrot", 12)
		|| !ft_strncmp(param[1], "-M", 2)
		|| !ft_strncmp(param[1], "--Burning_ship", 14)
		|| !ft_strncmp(param[1], "-B", 2))
		return (ft_is_mandelbrot_buring_ship(&data->name, param));
	if (ac == 4 && ((ft_strncmp(param[1], "--Julia", 7) == 0) \
		|| (ft_strncmp(param[1], "-J", 2) == 0)))
		return (ft_help_param(ft_julia_param(data, param)));
	else
		return (ft_help_param(-1));
}
