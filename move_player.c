#include "so_long.h"

static int		move_right(t_data *w)
{
	w->col = pos_in_colon(w->spt);
	w->row = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->row][w->col + 1] != '1' && w->spt[w->row][w->col + 1] != 'E')
	{
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/player.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, (w->col + 1) * size_pxl, w->row * size_pxl);
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/space.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, w->col * size_pxl, w->row * size_pxl);
		w->spt[w->row][w->col] = '0';
		w->spt[w->row][w->col + 1] = 'P';
		w->str = int_to_str(w->num++);
		mlx_string_put(w->mlx, w->window, 500, 0, 0xFFFFFF, w->str);
	}
	else if (w->spt[w->row][w->col + 1] == 'E' && w->count == 0)
	{
		free_and_exit(w);
	}
	return (0);
}

static int		move_down(t_data *w)
{
	w->col = pos_in_colon(w->spt);
	w->row = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->row + 1][w->col] != '1' && w->spt[w->row + 1][w->col] != 'E')
	{
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/player.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, (w->col) * size_pxl, (w->row + 1) * size_pxl);
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/space.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, w->col * size_pxl, w->row * size_pxl);
		w->spt[w->row][w->col] = '0';
		w->spt[w->row + 1][w->col] = 'P';
		w->str = int_to_str(w->num++);
		mlx_string_put(w->mlx, w->window, 500, 0, 0xFFFFFF, w->str);
	}
	else if (w->spt[w->row + 1][w->col] == 'E' && w->count == 0)
	{
		free_and_exit(w);
	}
	return (0);
}

static int		move_left(t_data *w)
{
	w->col = pos_in_colon(w->spt);
	w->row = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->row][w->col - 1] != '1' && w->spt[w->row][w->col - 1] != 'E')
	{
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/player.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, (w->col - 1) * size_pxl, w->row * size_pxl);
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/space.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, w->col * size_pxl, w->row * size_pxl);
		w->spt[w->row][w->col] = '0';
		w->spt[w->row][w->col - 1] = 'P';
		w->str = int_to_str(w->num++);
		mlx_string_put(w->mlx, w->window, 500, 0, 0xFFFFFF, w->str);
	}
	else if (w->spt[w->row][w->col - 1] == 'E' && w->count == 0)
	{
		free_and_exit(w);
	}
	return (0);
}

static int		move_up(t_data *w)
{
	w->col = pos_in_colon(w->spt);
	w->row = pos_in_row(w->spt);
	w->count = count_c(w->spt);
	if (w->spt[w->row - 1][w->col] != '1' && w->spt[w->row - 1][w->col] != 'E')
	{
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/player.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, (w->col) * size_pxl, (w->row - 1) * size_pxl);
		w->imag = mlx_xpm_file_to_image(w->mlx, "./image/space.xpm", &w->wid, &w->hei);
		mlx_put_image_to_window(w->mlx, w->window, w->imag, w->col * size_pxl, w->row * size_pxl);
		w->spt[w->row][w->col] = '0';
		w->spt[w->row - 1][w->col] = 'P';
		w->str = int_to_str(w->num++);
		mlx_string_put(w->mlx, w->window, 500, 0, 0xFFFFFF, w->str);
	}
	else if (w->spt[w->row - 1][w->col] == 'E' && w->count == 0)
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