/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:22:12 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/22 18:22:14 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	get_map_start(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] == '\n')
		i++;
	return (i);
}

int	get_map_width(char *content, int start)
{
	int	width;

	width = 0;
	while (content[start + width] != '\n'
		&& content[start + width] != '\0')
		width++;
	return (width);
}
