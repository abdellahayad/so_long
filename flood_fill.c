/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:56:40 by aayad             #+#    #+#             */
/*   Updated: 2025/02/15 21:28:25 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **free_copy(char **copy, int i)
{
	while (--i >= 0)
		free(copy[i]);
	free(copy);
	return (NULL);
}

int loop_map(char **map)
{
	int x;
	int	y;
	int	c;
	int e;
	
	c = 0;
	e = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				c++;
			if (map[x][y] == 'E')
			 e = 1;
			y++;
		}
		x++;
	}
	if (e != 0 || c != 0)
		return (free_copy(map, x), 1);
	free_copy(map, x);
	return (0);
}

char **copy_map(char **map)
{
	int		i;
	int		height;
	char **copy;

	height = 0;
	while (map[height])
		height++;
	copy = (char **)malloc((height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if(!copy[i])
			return (free_copy(copy, i));
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void  flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[x][y] || map[x][y] == '1' || map[x][y] == 'F')
		return ;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
int flood_fill_check(t_data *w)
{
	w->c = pos_in_colon(w->spt);
	w->r = pos_in_row(w->spt);
    char **copy;
	copy = copy_map(w->spt); 
    if (!copy)
        return (1);
    flood_fill(copy, w->r, w->c);
	if (loop_map(copy) == 1)
		return (1);
    return (0);
}
