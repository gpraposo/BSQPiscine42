/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:32:52 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/22 18:32:54 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <stdlib.h>

int	ft_min3(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

char	map_cell(char *content, t_map *map, int pos)
{
	int	x;
	int	y;

	y = pos / map->width;
	x = pos % map->width;
	return (content[map->start + y * (map->width + 1) + x]);
}

void	update_best(int *dp, int *best, int pos, int width)
{
	if (dp[pos] > best[0])
	{
		best[0] = dp[pos];
		best[1] = pos / width;
		best[2] = pos % width;
	}
}

void	fill_square(char *content, int *best, t_map *map)
{
	int	x;
	int	y;

	y = best[1] - best[0] + 1;
	while (y <= best[1])
	{
		x = best[2] - best[0] + 1;
		while (x <= best[2])
		{
			content[map->start + y * (map->width + 1) + x] = map->full;
			x++;
		}
		y++;
	}
}

int	solve_bsq(char *content, t_map *map)
{
	int	*dp;
	int	best[3];
	int	pos;

	dp = malloc(map->lines * map->width * sizeof(int));
	if (dp == 0)
		return (0);
	best[0] = 0;
	pos = 0;
	while (pos < map->lines * map->width)
	{
		if (map_cell(content, map, pos) == map->obstacle)
			dp[pos] = 0;
		else if (pos < map->width || pos % map->width == 0)
			dp[pos] = 1;
		else
			dp[pos] = 1 + ft_min3(dp[pos - 1], dp[pos - map->width],
					dp[pos - map->width - 1]);
		update_best(dp, best, pos, map->width);
		pos++;
	}
	if (best[0] > 0)
		fill_square(content, best, map);
	free(dp);
	return (1);
}
