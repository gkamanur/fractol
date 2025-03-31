/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:55:37 by gkamanur          #+#    #+#             */
/*   Updated: 2025/03/31 15:37:40 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractl.h"

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    
    if (!s1[i] || !s2[i])
        return (-1);  
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
void putstr_fd(char *str, int fd)
{
    while (*str)
        write(fd, str++, 1);
}

int char_check(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if (c == 32 || (c >= 9 && c <= 13))
        return (2);
    else
        return (0);
}

double ft_atodbl(const char *str)
{
    double res = 0.0;
    double fract = 0.0;
    int sign = 1;
    int i = 0;
    double div = 10.0;
    
    while (char_check(str[i]) == 2)
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    while (char_check(str[i]) == 1)
        res = res * 10.0 + (str[i++] - '0');
    if (str[i] == '.')
    {
        while (char_check(str[++i]) == 1)
        {
            fract = fract + (str[i] - '0') / div;
            div = div * 10.0;
        }
    }
    return (sign * (res + fract));
}

void	ft_putnbr_str(int n, char *str)
{
    int i = 0;
    int temp = n;
    if (n == 0)
        str[i++] = '0';
    else
    {
        if (n < 0)
        {
            str[i++] = '-';
            n = -n;
        }
        while (temp)  // Find the number of digits
        {
            temp /= 10;
            i++;
        }
        str[i] = '\0';
        while (n)  // Convert number to string
        {
            str[--i] = (n % 10) + '0';
            n /= 10;
        }
    }
}
