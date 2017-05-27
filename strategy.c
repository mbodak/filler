/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:39:57 by mbodak            #+#    #+#             */
/*   Updated: 2017/04/13 15:40:01 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		strategy_0(t_holder *hold, t_coords *coord_m, t_coords *coord_sh)
{
	coord_m->x = -100;
	while (coord_m->x < hold->high_map)
	{
		coord_m->y = -100;
		while (coord_m->y < hold->width_map)
		{
			if (can_fill_map(hold, coord_m, coord_sh))
			{
				ft_printf("%d %d\n", coord_m->x, coord_m->y);
				return (1);
			}
			coord_m->y++;
		}
		coord_m->x++;
	}
	ft_printf("0 0\n");
	return (0);
}

int		strategy_1(t_holder *hold, t_coords *coord_m, t_coords *coord_sh)
{
	coord_m->x = hold->high_map - 1;
	while (coord_m->x > -101)
	{
		coord_m->y = hold->width_map - 1;
		while (coord_m->y > -101)
		{
			if (can_fill_map(hold, coord_m, coord_sh))
			{
				ft_printf("%d %d\n", coord_m->x, coord_m->y);
				return (1);
			}
			coord_m->y--;
		}
		coord_m->x--;
	}
	ft_printf("0 0\n");
	return (0);
}

int		strategy_2(t_holder *hold, t_coords *coord_m, t_coords *coord_sh)
{
	coord_m->x = -100;
	while (coord_m->x < hold->high_map)
	{
		coord_m->y = hold->width_map - 1;
		while (coord_m->y > -101)
		{
			if (can_fill_map(hold, coord_m, coord_sh))
			{
				ft_printf("%d %d\n", coord_m->x, coord_m->y);
				return (1);
			}
			coord_m->y--;
		}
		coord_m->x++;
	}
	ft_printf("0 0\n");
	return (0);
}

int		strategy_3(t_holder *hold, t_coords *coord_m, t_coords *coord_sh)
{
	coord_m->x = hold->high_map - 1;
	while (coord_m->x > -101)
	{
		coord_m->y = -100;
		while (coord_m->y < hold->width_map)
		{
			if (can_fill_map(hold, coord_m, coord_sh))
			{
				ft_printf("%d %d\n", coord_m->x, coord_m->y);
				return (1);
			}
			coord_m->y++;
		}
		coord_m->x--;
	}
	ft_printf("0 0\n");
	return (0);
}

int		playing(t_holder *hold, t_coords *coord_m, t_coords *coord_sh)
{
	if (hold->direction == UP_LEFT)
		return (strategy_0(hold, coord_m, coord_sh));
	else if (hold->direction == DOWN_RIGHT)
		return (strategy_1(hold, coord_m, coord_sh));
	else if (hold->direction == UP_RIGHT)
		return (strategy_2(hold, coord_m, coord_sh));
	else if (hold->direction == DOWN_LEFT)
		return (strategy_3(hold, coord_m, coord_sh));
	return (0);
}
