/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:11:00 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/21 19:11:02 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_file_size(char *filename)
{
	int		fd;
	int		bytes;
	int		total;
	char	buffer[100];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	total = 0;
	bytes = read(fd, buffer, 100);
	while (bytes > 0)
	{
		total = total + bytes;
		bytes = read(fd, buffer, 100);
	}
	close(fd);
	if (bytes == -1)
		return (-1);
	return (total);
}

int	fill_content(char *filename, char *content, int total)
{
	int	fd;
	int	bytes;
	int	pos;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	pos = 0;
	bytes = read(fd, &content[pos], total - pos);
	while (bytes > 0)
	{
		pos = pos + bytes;
		bytes = read(fd, &content[pos], total - pos);
	}
	close(fd);
	if (bytes == -1)
		return (0);
	content[pos] = '\0';
	return (1);
}

char	*read_file(char *filename)
{
	char	*content;
	int		total;

	total = get_file_size(filename);
	if (total == -1)
		return (0);
	content = malloc(total + 1);
	if (content == 0)
		return (0);
	if (fill_content(filename, content, total) == 0)
	{
		free(content);
		return (0);
	}
	return (content);
}
