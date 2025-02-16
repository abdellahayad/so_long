/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procces_imag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:31:14 by aayad             #+#    #+#             */
/*   Updated: 2025/02/12 09:39:15 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_image_path(char elm)
{
	int		i;
	char	elements[5];
	char	*paths[5];

	elements[0] = '0';
	elements[1] = '1';
	elements[2] = 'E';
	elements[3] = 'P';
	elements[4] = 'C';
	paths[0] = "./img/C.xpm";
	paths[1] = "./img/W.xpm";
	paths[2] = "./img/door.xpm";
	paths[3] = "./img/P.xpm";
	paths[4] = "./img/key.xpm";
	i = 0;
	while (elements[i])
	{
		if (elm == elements[i])
			return (paths[i]);
		i++;
	}
	return (NULL);
}

void	change_element_to_img(char element, t_data *m)
{
	char	*path;

	path = get_image_path(element);
	if (!path)
		return ;
	m->img = mlx_xpm_file_to_image(m->mlx, path, &m->w, &m->h);
	if (!m->img)
	{
		ft_putstr("🔻Error: Failed to load image\n");
		ft_free(m);
		exit(1);
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->c * px, m->r * px);
}

void	create_game_features(t_data *w)
{
	w->r = 0;
	while (w->spt[w->r])
	{
		w->c = 0;
		while (w->spt[w->r][w->c])
		{
			change_element_to_img(w->spt[w->r][w->c], w);
			w->c++;
		}
		w->r++;
	}
}
