/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:38:52 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/22 19:38:54 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

static void	copy_bytes(char *dst, char *src, int start, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[start + i] = src[i];
		i++;
	}
}

static int	append_chunk(char **content, int *total, char *buf, int bytes)
{
	char	*new_content;

	new_content = malloc(*total + bytes + 1);
	if (new_content == 0)
	{
		free(*content);
		*content = 0;
		return (0);
	}
	copy_bytes(new_content, *content, 0, *total);
	copy_bytes(new_content, buf, *total, bytes);
	free(*content);
	*content = new_content;
	*total = *total + bytes;
	(*content)[*total] = '\0';
	return (1);
}

static char	*init_content(void)
{
	char	*content;

	content = malloc(1);
	if (content == 0)
		return (0);
	content[0] = '\0';
	return (content);
}

char	*read_stdin(void)
{
	char	buffer[100];
	char	*content;
	int		bytes;
	int		total;

	content = init_content();
	if (content == 0)
		return (0);
	total = 0;
	bytes = read(0, buffer, 100);
	while (bytes > 0)
	{
		if (append_chunk(&content, &total, buffer, bytes) == 0)
			return (0);
		bytes = read(0, buffer, 100);
	}
	if (bytes == -1)
	{
		free(content);
		return (0);
	}
	return (content);
}
