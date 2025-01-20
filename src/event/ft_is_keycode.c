/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_keycode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:27:58 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/20 13:11:26 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

inline int	ft_is_arrow(int keycode)
{
	return (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT);
}

inline int	ft_is_accuracy(int keycode)
{
	return (keycode == PLUS || keycode == MINUS);
}

inline int	ft_is_mv_base_point(int keycode, int name)
{
	return (name == JULIA
		&& (keycode == C || keycode == V || keycode == B || keycode == N));
}

inline int	ft_is_one(int keycode, int name)
{
	return (ft_is_arrow(keycode) || ft_is_accuracy(keycode)
		|| ft_is_mv_base_point(keycode, name));
}
