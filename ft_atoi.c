/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:47:23 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/20 23:07:56 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	ft_digittonum(char c)
{
	int	num;

	num = c - '0';
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	minus;

	num = 0;
	minus = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		minus = 1;
		nptr++;
		// if (!ft_isdigit(*(nptr + 10)) && !ft_strncmp(nptr, "2147483648", 10))
		// 	return (-2147483648);
	}
	while (ft_isdigit(*nptr))
		num = num * 10 + ft_digittonum(*nptr++);
	if (minus)
		num *= -1;
	return (num);
}

// # include <stdio.h>
// int	main(void)
// {
// 	char	teststring[] = "  \t\f\r\v  -2147483648ko0294385";

// 	printf("%d", ft_atoi(teststring));
// 	return (0);
// }
// // old version of else if (line 42ff)
// // 	else if (*nptr++ == '-')
// // 		minus = 1;
