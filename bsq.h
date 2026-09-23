/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-d <gprada-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:49:39 by gprada-d          #+#    #+#             */
/*   Updated: 2026/09/22 20:43:58 by gprada-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		lines;
	int		start;
	int		width;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

char	*read_file(char *filename);
char	*read_stdin(void);

int		parse_header(char *content, t_map *map);
int		validate_map(char *content, t_map *map);

int		get_map_start(char *content);
int		get_map_width(char *content, int start);

int		solve_bsq(char *content, t_map *map);

void	process_content(char *content);
void	process_file(char *filename);
void	process_stdin(void);

#endif
