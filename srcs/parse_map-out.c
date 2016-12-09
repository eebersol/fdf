/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <eebersol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:32:29 by eebersol          #+#    #+#             */
/*   Updated: 2016/10/26 13:06:04 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// print_line_hori((2 * y + x) / 2, (2 * y - x) / 2, (2 * y1 + x1) / 2, (2 * y - x) / 2, mlx, win);
// print_verti((2 * y + x) / 2, (2 * y - x) / 2, (2 * y + x) / 2, (2 * y1 - x1) / 2, mlx, win);
static void ft_lstshow(t_list *list)
{
	while (list && list->next)
	{
		printf("[%s]\n", (char *)list->content);
		list = list->next;
	}
}

int	 **put_value_array(void)
{
	t_list 	*list;
	t_point *point;
	int 	**array;
	char 	**line;
	int 	i;
	int 	x;

	list = recover_env()->list;
	array = NULL;
	if (list)
	{
		array = (int**)malloc(sizeof(int*) * (ft_lstcount(list) + 1));
		printf("[%d]\n", ft_lstcount(list));
		x = 0;
		while (list)
		{
			line = ft_strsplit((char*)list->content, ' ');
			array[x] = (int*)malloc(sizeof(int) * (ft_count_raw_aoc(line) + 1));
			i = 0;
			while (line[i])
			{
				array[x][i] = ft_atoi(line[i]);
				i++;
			}
			array[x][i] = '\0';
			x++;
			if (!list->next)
				break;
			list = list->next;

		}
		ft_print_aoi(array, x, ft_count_raw_aoi(array));
		recover_env()->winwidth = i;
		recover_env()->winheight = ft_count_raw_aoi(array);
	}
	return (array);
}

void 	get_mapinfo(int fd) 
{
	t_env *env;
	char *line;

	env = recover_env();
	line = NULL;
	while (ft_get_next_line(fd, &line))
		ft_lstaddend(&env->list, ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1)));
	ft_lstshow(env->list);
}

void	parse_map(char *map)
{
	t_env	*env;
	int		fd;
	char	*line;
	int 	**array;

	env = recover_env();
	line = NULL;
	array = NULL;
	if ((fd = open(map, 0)) == -1)
		ft_putendl_fd("Error occured can't open map.", 2);
	else
	{
		get_mapinfo(fd);
		array = put_value_array();
	}
}