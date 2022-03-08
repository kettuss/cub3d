/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:38:31 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/08 15:38:33 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_memory(char **memory, char **line)
{
	char	*p;

	p = NULL;
	if (*memory)
	{
		p = ft_strchr(*memory, '\n');
		if (p)
		{
			*p = '\0';
			*line = ft_strdup(*memory);
			p++;
			ft_strcpy(*memory, p);
		}
		else
		{
			*line = ft_strdup(*memory);
			free(*memory);
			*memory = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p);
}

int	ft_check_result(int readed, char **line)
{
	if (readed || !line)
		return (1);
	else
		return (0);
}

int	ft_checker_main(char **line, char *buf, int fd, char **memory)
{
	int		readed;
	char	*temp;
	char	*p;

	readed = 1;
	p = ft_check_memory(memory, line);
	while (!p && readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = '\0';
		p = ft_strchr(buf, '\n');
		if (p)
		{
			*p = '\0';
			*memory = ft_strdup(++p);
		}
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
	}
	return (readed);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			result;
	static char	*memory;

	if (read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	result = ft_checker_main(line, buf, fd, &memory);
	free(buf);
	return (ft_check_result(result, line));
}
