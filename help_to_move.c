/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:31:29 by aayad             #+#    #+#             */
/*   Updated: 2025/02/12 09:00:23 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int pos_in_colon(char **map)
{
	int		i;
	int		j;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int pos_in_row(char **map)
{
	int		i;
	int		j;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int count_c(char **map)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int free_and_exit(t_data *w)
{
	ft_free(w);
	mlx_destroy_window(w->mlx, w->win);
	ft_putstr("✅congratulation! you are win\n");
	exit(0);
}