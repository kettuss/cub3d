/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:53:24 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/07 19:39:41 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

int	ft_lgthword(char const *s, char c, int k)
{
	int	i;
	int	j;

	i = k;
	j = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_clean(char **str, int n)
{
	int	i;

	i = 0;
	if (!str || !n)
		return (0);
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_fillnewstr(char const *s, int n, char c, char **str)
{
	int	i;
	int	j;
	int	lgth;
	int	k;

	i = 0;
	k = 0;
	if (!s || !str)
		return (0);
	while (i < n)
	{
		j = 0;
		while (s[k] == c)
			k++;
		lgth = ft_lgthword(s, c, k);
		str[i] = (char *)malloc(sizeof(char) * (lgth + 1));
		if (!(str[i]))
			return (ft_clean(str, i));
		while (s[k] && s[k] != c)
			str[i][j++] = s[k++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		n;

	if (!s)
		return (NULL);
	n = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	str = ft_fillnewstr(s, n, c, str);
	return (str);
}
