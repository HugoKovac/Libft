/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:39:20 by hkovac            #+#    #+#             */
/*   Updated: 2021/11/29 12:50:58 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	nbstr(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while ((*s != c) && *s)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	*mall(char const *s, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

char	**ft_tmp(char const *s, char c, char **tab, int i)
{
	int	j;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		tab[i] = mall(s, c);
		if (!tab[i])
			return (ft_free(tab));
		j = 0;
		while (*s != c && *s)
			tab[i][j++] = *(s++);
		tab[i][j] = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof (char *) * (nbstr(s, c) + 1));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	return (ft_tmp(s, c, tab, 0));
}
