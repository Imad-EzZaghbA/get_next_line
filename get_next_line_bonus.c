/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:20:21 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/05 15:37:06 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_one_line(char *str, int j)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str)
		return (0);
	str2 = malloc(j + 2);
	if (!str2)
		return (NULL);
	while (i <= j)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*check(char **str1, char **str3, int *j)
{
	char	*str2;

	str2 = ft_one_line(*str1, *j);
	*str3 = *str1;
	*str1 = ft_substr(*str1, *j + 1, ft_strlen(*str1) - *j);
	return (free(*str3), str2);
}

char	*end_or_inv(int *u, char **buffer)
{
	char	*line;

	if (*u == 0)
	{
		if (ft_strlen(*buffer) == 0)
		{
			free(*buffer);
			*buffer = NULL;
		}
		line = ft_one_line(*buffer, ft_strlen(*buffer) - 1);
		free (*buffer);
		*buffer = NULL;
		return (line);
	}
	else if (*u == -1)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*ft_read(int fd, char **buffer, char *str)
{
	int			u;
	int			j;
	char		*tmp;

	j = 0;
	if (read(fd, str, 0) == -1)
	{
		free (*buffer);
		*buffer = NULL;
		return (free(str), NULL);
	}
	while (1)
	{
		j = ft_strchr(*buffer, '\n');
		if (j != -1)
			return (free (str), check(buffer, &tmp, &j));
		u = read(fd, str, BUFFER_SIZE);
		if (u == -1 || u == 0)
			return (free(str), end_or_inv(&u, buffer));
		str[u] = '\0';
		*buffer = ft_strjoin(*buffer, str);
	}
	free (*buffer);
	*buffer = NULL;
	return (free(str), NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*str;

	str = malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	if (fd >= 0 && BUFFER_SIZE > 0 && fd <= OPEN_MAX
			&& BUFFER_SIZE <= INT_MAX)
	{
		return (ft_read(fd, &buffer[fd], str));
	}
	return (free(str), NULL);
}
