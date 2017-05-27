/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 21:05:06 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/31 21:05:08 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_holder *hold)
{
	int		x;

	x = 0;
	if (hold->map == NULL)
		return ;
	while (hold->map[x])
	{
		free(hold->map[x]);
		x++;
	}
	free(hold->map);
	hold->map = NULL;
}

void	free_shape(t_holder *hold)
{
	int		x;

	x = 0;
	if (hold->shape == NULL)
		return ;
	while (hold->shape[x])
	{
		free(hold->shape[x]);
		x++;
	}
	free(hold->shape);
	hold->shape = NULL;
}

int		main(void)
{
	t_holder	*hold;
	t_coords	*coord_m;
	t_coords	*coord_sh;

	hold = (t_holder *)malloc(sizeof(t_holder));
	coord_m = (t_coords *)malloc(sizeof(t_coords));
	coord_sh = (t_coords *)malloc(sizeof(t_coords));
	initializer(hold, coord_m, coord_sh);
	find_sign(hold, coord_m);
	take_direction(hold);
	while (build_wall(hold, coord_m, coord_sh, 0))
	{
		update_map(hold);
		update_shape(hold);
		coord_m->x = -100;
	}
	free_map(hold);
	free_shape(hold);
	free(coord_m);
	free(coord_sh);
	free(hold);
	return (0);
}
