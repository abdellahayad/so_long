#include "so_long.h"

void	change_element_to_img(char element, t_data *map)
{
	if (element == '1')
	{
		map->imag = mlx_xpm_file_to_image(map->mlx, "./image/wall.xpm", &map->wid, &map->hei);
		mlx_put_image_to_window(map->mlx, map->window, map->imag, map->col * size_pxl, map->row * size_pxl);
	}
	if (element == 'E')
	{
		map->imag = mlx_xpm_file_to_image(map->mlx, "./image/door.xpm", &map->wid, &map->hei);
		mlx_put_image_to_window(map->mlx, map->window, map->imag, map->col * size_pxl, map->row * size_pxl);
	}
	if (element == 'P')
	{
		map->imag = mlx_xpm_file_to_image(map->mlx, "./image/player.xpm", &map->wid, &map->hei);
		mlx_put_image_to_window(map->mlx, map->window, map->imag, map->col * size_pxl, map->row * size_pxl);
	}
	if (element == '0')
	{
		map->imag = mlx_xpm_file_to_image(map->mlx, "./image/space.xpm", &map->wid, &map->hei);
		mlx_put_image_to_window(map->mlx, map->window, map->imag, map->col * size_pxl, map->row * size_pxl);
	}
	if (element == 'C')
	{
		map->imag = mlx_xpm_file_to_image(map->mlx, "./image/key.xpm", &map->wid, &map->hei);
		mlx_put_image_to_window(map->mlx, map->window, map->imag, map->col * size_pxl, map->row * size_pxl);
	}
}
void	create_game_features(t_data *w)
{
	w->row = 0;
	while (w->spt[w->row])
	{
		w->col = 0;
		while (w->spt[w->row][w->col])
		{
			change_element_to_img(w->spt[w->row][w->col], w);
			w->col++;
		}
		w->row++;
	}
}