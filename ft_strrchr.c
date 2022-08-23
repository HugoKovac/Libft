/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:23:25 by hkovac            #+#    #+#             */
/*   Updated: 2021/11/29 12:50:22 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		if (*(s++) == c)
			while (s)
				if (!*(s++))
					while (s--)
						if (*s == c)
							return ((char *)s);
	if (c == 0)
		return ((char *)s);
	return ((char *)0);
}