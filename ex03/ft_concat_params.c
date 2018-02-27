/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:03:42 by cdupuis           #+#    #+#             */
/*   Updated: 2018/02/21 11:59:47 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		len(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int cpt;

	i = 1;
	cpt = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}

char	*tab(int argc, char **argv)
{
	char	*concat;
	int		cpt;

	cpt = len(argc, argv);
	concat = (char*)malloc(sizeof(*concat) * (cpt + argc));
	if (concat == NULL)
		return (NULL);
	return (concat);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*concat;
	int		i;
	int		k;

	concat = tab(argc, argv);
	i = 1;
	k = 0;
	while (i < argc)
	{
		while (*argv[i])
		{
			concat[k] = *argv[i];
			k++;
			argv[i]++;
		}
		if (i != argc - 1)
		{
			concat[k] = '\n';
			k++;
		}
		i++;
	}
	concat[k] = '\0';
	return (concat);
}
