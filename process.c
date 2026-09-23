/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:20:19 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/22 19:20:21 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>

void	process_content(char *content)
{
	t_map	map;
	int		i;

	if (parse_header(content, &map) == 0
		|| validate_map(content, &map) == 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	solve_bsq(content, &map);
	i = map.start;
	while (content[i] != '\0')
	{
		write(1, &content[i], 1);
		i++;
	}
}

void	process_file(char *filename)
{
	char	*content;

	content = read_file(filename);
	if (content == 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	process_content(content);
	free(content);
}

void	process_stdin(void)
{
	char	*content;

	content = read_stdin();
	if (content == 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	process_content(content);
	free(content);
}
