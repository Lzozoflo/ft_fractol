/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_keycode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:27:58 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/23 09:23:31 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

inline int	ft_is_arrow_key(int keycode)
{
	return (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT);
}

inline int	ft_is_accuracy_key(int keycode)
{
	return (keycode == NUM_PAD_PLUS || keycode == NUM_PAD_MINUS
		|| keycode == NUM_PAD_ENTER);
}

inline int	ft_is_mv_base_point_key(int keycode, int name)
{
	return ((name == JULIA || name == JULIA_WITH_PARAM)
		&& (keycode == C || keycode == V || keycode == B || keycode == N));
}

inline int	ft_is_rbg_key(int keycode)
{
	return (keycode == NUM_PAD_4 || keycode == NUM_PAD_1
		|| keycode == NUM_PAD_5 || keycode == NUM_PAD_2
		|| keycode == NUM_PAD_6 || keycode == NUM_PAD_3);
}

inline int	ft_is_one_key(int keycode, int name)
{
	return (ft_is_arrow_key(keycode) || ft_is_accuracy_key(keycode)
		|| ft_is_mv_base_point_key(keycode, name) || ft_is_rbg_key(keycode)
		|| keycode == PLUS || keycode == MINUS);
}
