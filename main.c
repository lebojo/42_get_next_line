/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:00:23 by jchapell          #+#    #+#             */
/*   Updated: 2022/12/22 05:02:08 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i][0])
		i++;
	return (i);
}

int	ft_tab_copy(char **tab, char **tab2)
{
	int	i;
	int	ii;

	i = 0;
	while (tab[i][0])
	{
		ii = 0;
		tab[i] = malloc(sizeof(char) * (ft_strlen(tab2[i]) + 1));
		if (!tab[i])
			return (0);
		while (ii < (int)ft_strlen(tab2[i]))
		{
			tab[i][ii] = tab2[i][ii];
			ii++;
		}
		tab[i][ii] = '\0';
		i++;
		ii = 0;
	}
	return (i);
}

int	main(void)
{
	int		file, f1, f2, f3, f4, f5;
	int		i;
	int		nb_line;
	char	*tmp;

	// // sleep(10);
	// printf("\033[0;36m=== TEST N°\033[0;31m1\033[0;36m ===\n\033[0m\nOUTPUT:\n\n");
	// file = open("files2/nl", O_RDONLY);
	// i = 0;
	// nb_line = 19;
	// while (++i <= nb_line)
	// {
	// 	tmp = get_next_line(file);
	// 	printf("%d: %s", i, tmp);
	// 	free(tmp);
	// }
	// close(file);
	// printf("\033[0;32m\n\n=== PAS D'ERREUR ===\n");
	// // sleep(5);

	i = 0;
	while (++i < 5)
	{
		f1 = open("files/1", O_RDONLY);
		printf("%d\n", f1);
		wich_fd(f1, "", 0);
		f2 = open("files/2", O_RDONLY);
		printf("%d\n", f2);
		wich_fd(f2, "", 0);
		f3 = open("files/3", O_RDONLY);
		printf("%d\n", f3);
		wich_fd(f3, "", 0);
		f4 = open("files/4", O_RDONLY);
		printf("%d\n", f4);
		wich_fd(f4, "", 0);
		f5 = open("files/5", O_RDONLY);
		printf("%d\n", f5);
		wich_fd(f5, "", 0);

		wich_fd(f1, "", 0);
		wich_fd(f2, "", 0);
	}
}
