/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:31:52 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/08 16:07:33 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	fr_single(char **s1, char **s2)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

char	**concat_arg(int ac, char *av[])
{
	int		i;
	char	*ligne;
	char	*fr_ligne;
	char	*fr_ligne2;
	char	**sp;

	i = 0;
	ligne = ft_strdup("");
	while (++i < ac)
	{
		fr_ligne = ligne;
		fr_ligne2 = ft_strjoin(av[i], " ");
		ligne = ft_strjoin(fr_ligne, fr_ligne2);
		fr_single(&fr_ligne, &fr_ligne2);
	}
	sp = ft_split(ligne, ' ');
	free(ligne);
	return (sp);
}
