/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:53:28 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/22 17:53:29 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	check_map_char(char c, t_map *map, int *current, int *count)
{
	if (c == '\n')
	{
		if (*current != map->width)
			return (0);
		(*count)++;
		*current = 0;
	}
	else
	{
		if (c != map->empty && c != map->obstacle)
			return (0);
		(*current)++;
	}
	return (1);
}

int	validate_map(char *content, t_map *map)
{
	int	i;
	int	current;
	int	count;

	map->start = get_map_start(content);
	map->width = get_map_width(content, map->start);
	if (map->width <= 0)
		return (0);
	i = map->start;
	current = 0;
	count = 0;
	while (content[i] != '\0')
	{
		if (check_map_char(content[i], map, &current, &count) == 0)
			return (0);
		i++;
	}
	if (current != 0 || count != map->lines)
		return (0);
	return (1);
}
