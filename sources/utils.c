/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:29:25 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/09 17:30:32 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	ft_isdigit_base(char c)
{
	char	*digits;
	int		i;

	digits = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (digits[i] == ft_tolower(c))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str)
{
	long	result;
	size_t	i;

	result = 0;
	i = 2;
	while (ft_isdigit_base(str[i]) >= 0)
		result = result * 16 + ft_isdigit_base(str[i++]);
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		tmp = (tmp * 10) + (str[i] - 48);
		i++;
	}
	return (tmp * sign);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
