/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:03:06 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/29 13:03:09 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		init_sign(t_holder *hold)
{
	char	*line;

	get_next_line(FD, &line);
	if (line[10] == '1')
		hold->my_sign = 'o';
	else if (line[10] == '2')
		hold->my_sign = 'x';
	free(line);
}

static void		init_map(t_holder *hold)
{
	char	*line;
	int		i;

	i = 8;
	get_next_line(FD, &line);
	hold->high_map = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	hold->width_map = ft_atoi(line + i);
	free(line);
	hold->map = (char **)malloc(sizeof(char *) * (hold->high_map + 1));
	get_next_line(FD, &line);
	free(line);
	i = 0;
	while (i < hold->high_map)
	{
		get_next_line(FD, &line);
		hold->map[i] = ft_strsub(line, 4, (size_t)hold->width_map);
		free(line);
		i++;
	}
	hold->map[i] = NULL;
}

void			update_map(t_holder *hold)
{
	char	*line;
	int		i;

	i = 2;
	while (i > 0)
	{
		get_next_line(FD, &line);
		free(line);
		i--;
	}
	while (i < hold->high_map)
	{
		get_next_line(FD, &line);
		hold->map[i] = ft_strsub(line, 4, (size_t)hold->width_map);
		free(line);
		i++;
	}
}

void			update_shape(t_holder *hold)
{
	char	*line;
	int		j;

	j = 6;
	get_next_line(FD, &line);
	hold->high_shape = ft_atoi(line + j);
	while (ft_isdigit(line[j]))
		j++;
	hold->width_shape = ft_atoi(line + j);
	free(line);
	free_shape(hold);
	hold->shape = (char **)malloc(sizeof(char *) * (hold->high_shape + 1));
	j = 0;
	while (j < hold->high_shape)
	{
		get_next_line(FD, &line);
		hold->shape[j++] = line;
	}
	hold->shape[j] = NULL;
}

void			initializer(t_holder *hold, t_coords *c_m, t_coords *c_sh)
{
	hold->map = NULL;
	hold->shape = NULL;
	hold->line_num = -1;
	hold->column_num = -1;
	c_m->x = 0;
	c_m->y = 0;
	c_sh->x = 0;
	c_sh->y = 0;
	init_sign(hold);
	init_map(hold);
	update_shape(hold);
}
