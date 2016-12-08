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
		printf("[%d][%d]\n", x, i);
		ft_print_aoi(array, x, i);
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
	{
		ft_lstaddend(&env->list, ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1)));
		env->winsize++;
	}
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