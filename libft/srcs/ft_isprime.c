/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 21:34:47 by okrifa            #+#    #+#             */
/*   Updated: 2016/01/14 16:51:01 by okrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_isprime(unsigned int n)
{
	unsigned int i;

	i = 2;
	while (i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}