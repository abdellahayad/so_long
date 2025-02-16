/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:32:30 by aayad             #+#    #+#             */
/*   Updated: 2025/02/15 21:33:22 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f()
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
	atexit(f);
	t_data	w;

	w = (t_data){};
	if (ac == 2)
	{

		if (check_map(av[1], &w) == 1)
			return (0);
		w.mlx = mlx_init();
        w.length = ft_strlen(w.spt[0]) * px;
        w.width = count_row(w.spt, w) * px;
        w.win = mlx_new_window(w.mlx, w.length, w.width, "so_long");
		create_game_features(&w);
		w.str = int_to_str(w.num++);
		mlx_string_put(w.mlx, w.win, 500, 0, 0xFFFFFF, w.str);
		free(w.str);
		mlx_key_hook(w.win, esc, &w);
		mlx_hook(w.win, 17, 1L << 0, close_win, &w);
		mlx_hook(w.win, 02, 1L << 0, move_player, &w);
        mlx_loop(w.mlx);
		ft_free(&w);
	}
	else
		return (0);
}
	