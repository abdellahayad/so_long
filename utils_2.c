/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_soo_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:33:03 by aayad             #+#    #+#             */
/*   Updated: 2025/02/11 18:33:04 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strcount(char **spt, char elm)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	j = 0 ;
	while (spt[i])
	{
		j = 0;
		while (spt[i][j])
		{
			if (spt[i][j] == elm)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
int count_row(char **spt, t_data w)
{
	w.r = 0;
	while (spt[w.r])
	{
		w.c = 0;
		while (spt[w.r][w.c])
			w.c++;
		w.r++;
	}
	return (w.r);
}

void ft_free(t_data *w)
{
	int i;

	i = 0;
	while (w->spt[i])
	{
		free(w->spt[i]);
		i++;
	}
	free(w->spt);
}

int esc(int esc, t_data *w)
{

	if (esc == 53)
	{
		ft_free(w);
		free(w->lines);
		exit (0);
	}
	return (0);
}

int close_win(t_data *w)
{
	ft_free(w);
	free(w->lines);
	exit(0);
}
