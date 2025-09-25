/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:00:26 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/11 23:26:26 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	*ft_clear(char **p, char *ptr)
{
	if (p)
	{
		free(*p);
		*p = NULL;
	}
	free(ptr);
	return (NULL);
}

char	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (c);
		s++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2, char c)
{
	char	*p;
	size_t	i;
	size_t	sl1;
	size_t	sl2;

	i = 0;
	sl1 = ft_strlen_gnl(s1, c);
	sl2 = ft_strlen_gnl(s2, c);
	if (!sl1 && !sl2)
		return (NULL);
	p = (char *)malloc(sl2 + sl1 + 1);
	if (!p)
		return (NULL);
	while (s1 != NULL && i < sl1 && *s1)
		p[i++] = *s1++;
	while (s2 != NULL && i < sl2 + sl1 && *s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen_gnl(char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	if (!s)
		return (0);
	while (s[cnt] && s[cnt] != c)
		cnt++;
	if (s[cnt] == '\n')
		cnt++;
	return (cnt);
}

char	*ft_substr_gnl(char *s, int i_str, char c)
{
	size_t	slen;
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (i_str && *s)
	{
		if (*s++ == '\n')
			break ;
	}
	slen = ft_strlen_gnl(s, c);
	if (!slen)
		return (NULL);
	ptr = (char *)malloc(slen + 1);
	if (!ptr)
		return (NULL);
	while (i < slen)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[slen] = '\0';
	return (ptr);
}
