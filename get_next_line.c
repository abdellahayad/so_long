/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:56:02 by aayad             #+#    #+#             */
/*   Updated: 2025/02/15 18:56:18 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char	buff[1];
	char	str[100];
	char	*line;
	int		i;

	i = 0;
	str[0] = '\0';
	while (read(fd, buff, 1) > 0)
	{
		str[i] = buff[0];
		str[i + 1] = '\0';
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[0] == '\0')
		return (NULL);
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i])
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}