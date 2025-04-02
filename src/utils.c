/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:55:37 by gkamanur          #+#    #+#             */
/*   Updated: 2025/04/02 12:03:15 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractl.h"

int	char_check(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == 32 || (c >= 9 && c <= 13))
		return (2);
	else
		return (0);
}

void	ft_putnbr_str(int n, char *str, int i)
{
	int	temp;

	temp = n;
	if (n == 0)
		str[i++] = '0';
	else
	{
		if (n < 0)
		{
			str[i++] = '-';
			n = -n;
		}
		while (temp)
		{
			temp /= 10;
			i++;
		}
		str[i] = '\0';
		while (n)
		{
			str[--i] = (n % 10) + '0';
			n /= 10;
		}
	}
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
