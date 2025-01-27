/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:26:50 by fcretin           #+#    #+#             */
/*   Updated: 2025/01/21 18:29:26 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (!((*str > 47 && *str < 58) || *str == ' '))
			return (0);
		str++;
	}
	return (1);
}

/**
 * @brief Checks if a character is a decimal digit.
 *
 * The function `ft_isdigit` tests if the character passed as argument `c`
 * corresponds to a decimal digit (from '0' to '9'). It uses ASCII codes
 * to check if `c` is within the range of digits (from 48 to 57).
 *
 * @param c The character to test, represented as an integer (`int`).
 *          In C, characters are often passed as integers, allowing us to
 *          check their ASCII codes.
 * @return int Returns 1 if the character is a decimal digit (from '0' to '9'),
 *             and 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_digit_sign(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == ' ')
			str++;
		else if (*str == '-' || *str == '+')
		{
			if (ft_isdigit(*(str + 1)) && (str == start || *(str - 1) == ' '))
				str++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_digit_sign_float(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == ' ')
			str++;
		else if (*str == '-' || *str == '+')
		{
			if (ft_isdigit(*(str + 1)) && (str == start || *(str - 1) == ' '))
				str++;
			else
				return (0);
		}
		else if (*str == '.' && str != start
			&& ft_isdigit(*(str - 1)) && ft_isdigit(*(str + 1)))
			str++;
		else
			return (0);
	}
	return (1);
}
