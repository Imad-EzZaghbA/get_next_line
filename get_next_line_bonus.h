/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 05:21:43 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/04 08:05:31 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
int		ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif