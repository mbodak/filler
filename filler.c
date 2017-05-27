/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:26:56 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/13 15:56:41 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_sign(t_holder *hold, t_coords *co_m)
{
	co_m->x = 0;
	while (co_m->x < hold->high_map)
	{
		co_m->y = 0;
		while (co_m->y < hold->width_map)
		{
			if (hold->map[co_m->x][co_m->y] == ft_toupper((int)hold->my_sign))
			{
				hold->line_num = co_m->x;
				hold->column_num = co_m->y;
				return (1);
			}
			co_m->y++;
		}
		co_m->x++;
	}
	co_m->x = -100;
	co_m->y = -100;
	return (0);
}

void	take_direction(t_holder *hold)
{
	if ((hold->line_num > hold->high_map / 2)
		&& (hold->column_num > hold->width_map / 2))
		hold->direction = UP_LEFT;
	else if ((hold->line_num > hold->high_map / 2)
			&& (hold->column_num < hold->width_map / 2))
		hold->direction = UP_RIGHT;
	else if ((hold->line_num < hold->high_map / 2)
			&& (hold->column_num > hold->width_map / 2))
		hold->direction = DOWN_LEFT;
	else if ((hold->line_num < hold->high_map / 2)
			&& (hold->column_num < hold->width_map / 2))
		hold->direction = DOWN_RIGHT;
}

int		count_stars(t_holder *hold, t_coords *coord_m, t_coords *coord_sh)
{
	int		stars;
	int		new_x;

	stars = 0;
	new_x = 0;
	coord_sh->x = 0;
	while (coord_sh->x < hold->high_shape)
	{
		coord_sh->y = 0;
		while (coord_sh->y < hold->width_shape)
		{
			if (hold->shape[coord_sh->x][coord_sh->y] == '*')
				new_x = coord_m->x + coord_sh->x;
			if (new_x == hold->line_num)
				stars++;
			coord_sh->y++;
		}
		coord_sh->x++;
	}
	return (stars);
}

int		build_wall(t_holder *hold, t_coords *coord_m, t_coords *coord_sh, int m)
{
	int			stars;
	t_coords	best;

	while (coord_m->x < hold->high_map)
	{
		coord_m->y = -100;
		while (coord_m->y < hold->width_map)
		{
			if (can_fill_map(hold, coord_m, coord_sh))
			{
				if (m < (stars = count_stars(hold, coord_m, coord_sh)))
				{
					m = stars;
					best.x = coord_m->x;
					best.y = coord_m->y;
				}
			}
			coord_m->y++;
		}
		coord_m->x++;
	}
	if (!m)
		return (playing(hold, coord_m, coord_sh));
	ft_printf("%d %d\n", best.x, best.y);
	return (1);
}
