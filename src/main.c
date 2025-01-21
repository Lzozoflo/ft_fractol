/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/21 21:02:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_param(ac, av, &data))
		return (1);
	if (!ft_init(&data))
		return (1);
	ft_who_draw(&data);
	mlx_loop(data.mlx);
}
