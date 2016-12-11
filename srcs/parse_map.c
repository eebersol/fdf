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

// static void free_node(void *elem, size_t size)
// {
// 	(void)size;

// 	if (elem)
// 		free(elem);
// }

static void ft_lstshow(t_list *list)
{

	while (list)
	{
		printf("[%s]\n", (char *)list->content);
		if (!list->next)
			return ;
		list = list->next;
	}
}

// static void ft_lstshow_coord(t_list *list)
// {
// 	t_point *point;

// 	while (list && list->next)
// 	{
// 		point = list->content;
// 		printf("s : [%f]\n", point->s);
// 		printf("x [%f]\n", point->x);
// 		printf("y [%f\n", point->y);
// 		list = list->next;
// 	}
// }
static void new_size()
{
	t_env *env;

	env = recover_env();
	env->len_map = env->height - (env->height * 0.6);
	env->len_map /= 2;
}
void 	put_value_tolist(void)
{
	t_env 	*env;
	t_list 	*list;
	t_list 	*cur;
	t_point *point;
	char 	**line;
	int 	i;
	int 	j;

	env = recover_env();
	list = env->list;
	cur = (t_list*)malloc(sizeof(t_list));
	new_size();
	env->twidth = (env->width)/(ft_count_raw_aoc(ft_strsplit((char*)list->content, ' ')));
	env->theight = (env->height)/(ft_lstcount(env->list));
	j = 0;
	if (list)
	{
		while (list)
		{
			line = ft_strsplit((char*)list->content, ' ');
			i = 0;
			while (i < ft_count_raw_aoc(line))
			{
				point = init_point();
				point->z = ft_atoi(line[i]);
				point->x = (i * (env->twidth * 0.6)) - 150;
				point->y = (j * ((env->theight * 0.6))) + env->len_map * 1.1;
				ft_lstaddend(&cur, ft_lstnew(point, sizeof(t_point)));
				i++;
			}
			j++;
			if (!list->next)
			{
				printf("x [%f]\n", env->height - point->x);
				break;
			}
			list = list->next;
		}
		env->x_size = i;
		env->y_size = j;
	}
	env->list = cur;
	// if (env->type == 'I')
	// 	cartesian_to_isometric();
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

	env = recover_env();
	if ((fd = open(map, 0)) == -1)
		ft_putendl_fd("Error occured can't open map.", 2);
	else
	{
		get_mapinfo(fd);
		put_value_tolist();
	}
}