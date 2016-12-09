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

static void free_node(void *elem, size_t size)
{
	if (elem)
	{
		free(elem);
	}
}

static void ft_lstshow(t_list *list)
{
	while (list && list->next)
	{
		printf("[%s]\n", (char *)list->content);
		list = list->next;
	}
}

void 	put_value_tolist(void)
{
	t_env 	*env;
	t_list 	*list;
	t_point *point;
	char 	**line;
	int 	i;
	int 	x;

	list = env->list;
	ft_lstdel(&env->list, &free_node);
	env->twidth = ft_strlen((char*)list->content);
	env->theight = ft_lstcount(list)/env->twidth;
	if (list)
	{
		x = 0;
		while (list)
		{
			point = init_point();
			env->list->content = point
			line = ft_strsplit((char*)list->content, ' ');
			i = 0;
			while (line[i])
			{
				point->s = ft_atoi(line[i]);
				point->x = env->height/env->theight;
				point->y = env->width/env->twidth;
				ft_lstaddend(&env->list, ft_lstnew(point, sizeof(t_point)));
				i++;
			}
			if (!list->next)
				break;
			list = list->next;

		}
	}
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
		put_value_t_list();
	}
}