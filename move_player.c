/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_P.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:31:52 by aayad             #+#    #+#             */
/*   Updated: 2025/02/11 21:33:38 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_right(t_data *w)
{
	w->c = pos_in_colon(w->spt);
	w->r = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->r][w->c + 1] != '1' && w->spt[w->r][w->c + 1] != 'E')
	{
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/P.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win,
			w->img, (w->c + 1) * px, w->r * px);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/C.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, w->c * px, w->r * px);
		w->spt[w->r][w->c] = '0';
		w->spt[w->r][w->c + 1] = 'P';
		w->str = int_to_str(w->num++);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/W.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, 500, 0);
		mlx_string_put(w->mlx, w->win, 500, 0, 0xFFFFFF, w->str);
		free(w->str);
	}
	else if (w->spt[w->r][w->c + 1] == 'E' && w->count == 0)
	{
		free_and_exit(w);
	}
	return (0);
}

static int	move_down(t_data *w)
{
	w->c = pos_in_colon(w->spt);
	w->r = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->r + 1][w->c] != '1' && w->spt[w->r + 1][w->c] != 'E')
	{
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/P.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win,
			w->img, (w->c) * px, (w->r + 1) * px);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/C.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, w->c * px, w->r * px);
		w->spt[w->r][w->c] = '0';
		w->spt[w->r + 1][w->c] = 'P';
		w->str = int_to_str(w->num++);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/W.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, 500, 0);
		mlx_string_put(w->mlx, w->win, 500, 0, 0xFFFFFF, w->str);
		free(w->str);
	}
	else if (w->spt[w->r + 1][w->c] == 'E' && w->count == 0)
	{
		free_and_exit(w);
	}
	return (0);
}

static int	move_left(t_data *w)
{
	w->c = pos_in_colon(w->spt);
	w->r = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->r][w->c - 1] != '1' && w->spt[w->r][w->c - 1] != 'E')
	{
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/P.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win,
			w->img, (w->c - 1) * px, w->r * px);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/C.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, w->c * px, w->r * px);
		w->spt[w->r][w->c] = '0';
		w->spt[w->r][w->c - 1] = 'P';
		w->str = int_to_str(w->num++);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/W.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, 500, 0);
		mlx_string_put(w->mlx, w->win, 500, 0, 0xFFFFFF, w->str);
		free(w->str);
	}
	else if (w->spt[w->r][w->c - 1] == 'E' && w->count == 0)
	{
		free_and_exit(w);
	}
	return (0);
}

static int	move_up(t_data *w)
{
	w->c = pos_in_colon(w->spt);
	w->r = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->r - 1][w->c] != '1' && w->spt[w->r - 1][w->c] != 'E')
	{
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/P.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx,
			w->win, w->img, (w->c) * px, (w->r - 1) * px);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/C.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, w->c * px, w->r * px);
		w->spt[w->r][w->c] = '0';
		w->spt[w->r - 1][w->c] = 'P';
		w->str = int_to_str(w->num++);
		w->img = mlx_xpm_file_to_image(w->mlx, "./img/W.xpm", &w->w, &w->h);
		mlx_put_image_to_window(w->mlx, w->win, w->img, 500, 0);
		mlx_string_put(w->mlx, w->win, 500, 0, 0xFFFFFF, w->str);
		free(w->str);
	}
	else if (w->spt[w->r - 1][w->c] == 'E' && w->count == 0)
	{
		free_and_exit(w);
	}
	return (0);
}

int	move_player(int key, t_data *w)
{
	if (key == 124)
		move_right(w);
	if (key == 125)
		move_down(w);
	if (key == 126)
		move_up(w);
	if (key == 123)
		move_left(w);
	return (0);
}
