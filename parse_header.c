/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:43:06 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/22 17:43:08 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	parse_line_count(char *content, int end, t_map *map)
{
	int	i;

	i = 0;
	map->lines = 0;
	while (i < end)
	{
		if (content[i] < '0' || content[i] > '9')
			return (0);
		map->lines = map->lines * 10 + (content[i] - '0');
		i++;
	}
	if (map->lines <= 0)
		return (0);
	return (1);
}

int	valid_symbols(t_map *map)
{
	if (map->empty < 32 || map->empty > 126)
		return (0);
	if (map->obstacle < 32 || map->obstacle > 126)
		return (0);
	if (map->full < 32 || map->full > 126)
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

int	parse_header(char *content, t_map *map)
{
	int	i;

	i = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] != '\n' || i < 4)
		return (0);
	map->empty = content[i - 3];
	map->obstacle = content[i - 2];
	map->full = content[i - 1];
	if (valid_symbols(map) == 0)
		return (0);
	if (parse_line_count(content, i - 3, map) == 0)
		return (0);
	return (1);
}
