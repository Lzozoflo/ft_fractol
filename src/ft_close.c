/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:46:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/14 17:25:20 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_idk.h"

int	ft_cross_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	ft_clean_close(data, 0);
	exit (0);
}

int	ft_clean_close(t_data *data, int error)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	printf("Exiting program.\n");
	exit(error);
}
