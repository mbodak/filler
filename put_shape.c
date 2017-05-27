/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 21:07:53 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/31 21:08:01 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_sign(t_holder *hold, t_coords new_m)
{
	if (hold->my_sign == 'x')
	{
		if (hold->map[new_m.x][new_m.y] == 'X')
			return (1);
		if (hold->map[new_m.x][new_m.y] == 'x')
			return (1);
	}
	else if (hold->my_sign == 'o')
	{
		if (hold->map[new_m.x][new_m.y] == 'O')
			return (1);
		if (hold->map[new_m.x][new_m.y] == 'o')
			return (1);
	}
	return (0);
}

int		check_coords(t_coords new_m, t_holder *hold, int *count)
{
	if ((new_m.x >= hold->high_map || new_m.y >= hold->width_map)
		|| (new_m.x < 0 || new_m.y < 0))
		return (0);
	else if (!*count && check_sign(hold, new_m))
		*count = 1;
	else if (*count && check_sign(hold, new_m))
		return (0);
	return (1);
}

int		detection_enemy(t_holder *hold, t_coords new_m)
{
	if (hold->my_sign == 'x')
	{
		if (hold->map[new_m.x][new_m.y] == 'O')
			return (1);
		if (hold->map[new_m.x][new_m.y] == 'o')
			return (1);
	}
	else if (hold->my_sign == 'o')
	{
		if (hold->map[new_m.x][new_m.y] == 'X')
			return (1);
		if (hold->map[new_m.x][new_m.y] == 'x')
			return (1);
	}
	return (0);
}

int		can_fill_map(t_holder *hold, t_coords *coord_m, t_coords *coord_sh)
{
	t_coords	new_m;
	int			count;

	count = 0;
	coord_sh->x = 0;
	while (coord_sh->x < hold->high_shape)
	{
		coord_sh->y = 0;
		while (coord_sh->y < hold->width_shape)
		{
			if (hold->shape[coord_sh->x][coord_sh->y] == '*')
			{
				new_m.x = coord_m->x + coord_sh->x;
				new_m.y = coord_m->y + coord_sh->y;
				if (!check_coords(new_m, hold, &count))
					return (0);
				if (detection_enemy(hold, new_m))
					return (0);
			}
			coord_sh->y++;
		}
		coord_sh->x++;
	}
	return (count);
}
