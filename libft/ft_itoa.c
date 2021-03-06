/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:48:26 by mbodak            #+#    #+#             */
/*   Updated: 2016/12/15 15:22:18 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;
	int		negative;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 0;
	while (tmp /= 10)
		len++;
	negative = 0;
	if (n < 0 && (negative = 1))
		n = -n;
	if (!(res = (char *)malloc(sizeof(char) * ((len += negative + 1) + 1))))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = ((n % 10) + 48);
		n /= 10;
	}
	if (negative)
		res[0] = '-';
	return (res);
}
