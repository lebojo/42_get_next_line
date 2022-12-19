/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:59:44 by jchapell          #+#    #+#             */
/*   Updated: 2022/12/14 00:35:37 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*parse_line(char **s)
{
	int		i;
	char	*res;

	i = 0;
	while (s && s[0] && s[0][i] && s[0][i] != '\n')
		i++;
	if (i == (int)ft_strlen(s[0]))
	{
		res = ft_strjoin(s[0], "");
		s[0] = NULL;
		return (res);
	}
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (0);
	i = -1;
	while (s[0][++i] != '\n')
		res[i] = s[0][i];
	s[0] = get_afternewline(s[0]);
	res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*res;
	int			rd;
	static char	*last_buffer = NULL;

	rd = -1;
	if (last_buffer && ft_strchr(last_buffer, '\n', rd))
	{
		res = parse_line(&last_buffer);
		return (res);
	}
	while (!ft_strchr(last_buffer, '\n', rd))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (0);
		buf[rd] = '\0';
		if (rd != BUFFER_SIZE)
			return (end_nullifier(&last_buffer, buf));
		last_buffer = ft_strjoin(last_buffer, buf);
	}
	res = parse_line(&last_buffer);
	return (res);
}

// int	main(void)
// {
// 	int		file;
// 	int		i;
// 	int		nb_line;
// 	char	*tmp;

// 	printf("\033[0;36m=== TEsST N°\033[0;31m1\033[0;36m ===\n\033[0m\nOUTPUT:\n\n");
// 	file = open("files/only_nl.txt", O_RDONLY);
// 	i = 0;
// 	nb_line = 19;
// 	while (++i <= nb_line)
// 	{
// 		tmp = get_next_line(file);
// 		printf("%d: %s", i, tmp);
// 		free(tmp);
// 	}
// 	close(file);
// 	printf("\033[0;32m\n\n=== PAS D'ERREUR ===\n");

// }
