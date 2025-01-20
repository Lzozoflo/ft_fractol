/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/20 11:48:06 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdlib.h>

/*
void	ft_param(int ac, char **av, t_data *data)
{
	what fractol his init if julia
	and more idk

}
*/

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_param(ac, av[1], &data))
		return (1);
	if (!ft_init(&data))
		return (1);
	ft_who_draw(&data);
	mlx_loop(data.mlx);
}
