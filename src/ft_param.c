/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:24:15 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/20 13:00:31 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include "libft.h"

int	ft_help_key(void)
{
	ft_printf("+-----------------------------------------------------+\n");
	ft_printf("|                                                     |\n");
	ft_printf("|   Quit                 : ESC                        |\n");
	ft_printf("|   Arrow for moving     : UP, DOWN, LEFT, RIGHT      |\n");
	ft_printf("|   Zoom in (on target)  : LEFT_CLICK, SCROLL_UP      |\n");
	ft_printf("|   Zoom in (on target)  : RIGHT_CLICK, SCROLL_DOWN   |\n");
	ft_printf("|   More details         : num pad +, num pad -       |\n");
	ft_printf("|   Julia only           :                            |\n");
	ft_printf("|   *         C (real++), V (real--)                  |\n");
	ft_printf("|   *         B (imag++), N (imag--)                  |\n");
	ft_printf("|                                                     |\n");
	ft_printf("+-----------------------------------------------------+\n");
	return (0);
}

int	ft_help_param(void)
{
	ft_printf("+-----------------------------------------------------+\n");
	ft_printf("|                                                     |\n");
	ft_printf("|   Empty Param ---> ./fractol <param>                |\n");
	ft_printf("|   Available :                                       |\n");
	ft_printf("|   * Julia, -J                                       |\n");
	ft_printf("|   * Mandelbrot, -M                                  |\n");
	ft_printf("|   Setting Key : Help_key, -H                        |\n");
	ft_printf("|                                                     |\n");
	ft_printf("+-----------------------------------------------------+\n");
	return (0);
}

int	ft_param(int ac, char *param, t_data *data)
{
	if (ac == 1)
		return (ft_help_param());
	else if (ft_strncmp(param, "Help_key", 8) == 0
		|| ft_strncmp(param, "-H", 2) == 0)
		return (ft_help_key());
	else if (ft_strncmp(param, "Julia", 5) == 0
		|| ft_strncmp(param, "-J", 2) == 0)
	{
		data->name = JULIA;
		return (1);
	}
	else if (!ft_strncmp(param, "Mandelbrot", 5)
		|| !ft_strncmp(param, "-M", 2))
	{
		data->name = MANDELBROT;
		return (1);
	}
	else if (ac != 1)
		return (ft_help_param());
	return (0);
}
