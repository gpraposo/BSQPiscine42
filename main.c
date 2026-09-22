/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:12:40 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/21 18:12:41 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		bytes;
	char	buffer[100];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
		bytes = read(fd, buffer, 100);
		while (bytes > 0)
		{
			write(1, buffer, bytes);
			bytes = read(fd, buffer, 100);
		}
		close(fd);
	}
	return (0);
}
