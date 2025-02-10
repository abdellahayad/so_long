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
        w.length = ft_strlen(w.spt[0]) * size_pxl;
        w.width = count_row(w.spt, w) * size_pxl;
        w.window = mlx_new_window(w.mlx, w.length, w.width, "so_long");
		create_game_features(&w);
		w.str = int_to_str(w.num++);
		mlx_string_put(w.mlx, w.window, 500, 0, 0xFFFFFF, w.str);
		mlx_key_hook(w.window, esc, &w);
		mlx_hook(w.window, 17, 1L << 0, close_win, &w);
		mlx_hook(w.window, 02, 1L << 0, move_player, &w);
        mlx_loop(w.mlx);
	}
	else
		return (0);
}