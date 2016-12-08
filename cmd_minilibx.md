{void *mlx_init()} 

{void *mlx_new_window(void *mlx_ptr, int width, int height, char *title)}

.créer une nouvelle fenêtre à l'écran.

{int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)}

.affiche un pixel en couleur





Evènement : 

.clavier : if key is press minilibx call your function gere_key(int keycode, void *param);