/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:40:55 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/07 19:44:40 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i]
		== (unsigned char)s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *s)
{
	unsigned int	res;
	int				i;
	int				k;

	k = 1;
	i = 0;
	res = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\f'
		|| s[i] == '\r' || s[i] == '\n' || s[i] == '\v')
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			k = -1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(k * res));
}
