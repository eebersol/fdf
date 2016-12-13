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
	printf("[%f][%f]\n", env->height, env->width);
	env->len_map = sqrt(((env->width/2)*(env->width/2)) + ((env->width/2)*(env->width/2)));
	env->len_map /= 2;
}
void 	put_value_tolist(void)
{
	t_env 	*env;
	t_list 	*list;
	t_list 	*cur;
	t_point *point;
	double 	tmp;
	char 	**line;
	int 	i;
	int 	j;

	env = recover_env();
	list = env->list;
	cur = (t_list*)malloc(sizeof(t_list));
	new_size();
	env->twidth = (env->width/1.5)/(ft_count_raw_aoc(ft_strsplit((char*)list->content, ' ')));
	env->theight = (env->height/1.5)/(ft_lstcount(env->list));
	env->theight = env->twidth;
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
				point->x = i * (env->twidth/2) + 250;
				point->y = j * (env->theight) + 50;
				printf("1 Add [%f][%f]\n", point->y, point->x);
				tmp = point->y;
				// printf("tmp : [%f]\n", tmp);
				// point->y = (2 * point->y + point->x)/2;
				// point->x = (2 * tmp - point->x)/2;
				if (i == 0 & j == 0)
					env->x_size = point->y;
				// printf("2 : Add [%f][%f]\n", point->y, point->x);
				ft_lstaddend(&cur, ft_lstnew(point, sizeof(t_point)));
				i++;
			}
			if (!list->next)
			{
				break;
			}
			list = list->next;
			j++;
		}
		env->x_size = i + 1;
		env->y_size = j + 1;
	}
	env->list = cur;
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