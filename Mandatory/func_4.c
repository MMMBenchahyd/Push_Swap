/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:29:13 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/09 18:29:28 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	f_dlmt(char c, char s)
{
	if (s == c && s)
		return (1);
	return (0);
}

static int	ft_strlen_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && !f_dlmt(*s, c))
	{
		i++;
		s++;
	}
	return (i);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!f_dlmt(s[i], c) && f_dlmt(s[i + 1], c))
			count++;
		i++;
	}
	if (i && !f_dlmt(s[--i], c))
		count++;
	return (count);
}

static char	*ft_strdupn(char const **s, char c)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	while (f_dlmt(**s, c))
		*s += 1;
	size = ft_strlen_c(*s, c);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	while (**s && !f_dlmt(**s, c))
	{
		ptr[i++] = **s;
		*s += 1;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**ptr;

	i = 0;
	if (!s)
		return (NULL);
	words = count_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	while (i < words)
	{
		ptr[i] = ft_strdupn(&s, c);
		if (!ptr[i])
		{
			while (i + 1)
				free(ptr[i--]);
			free(ptr);
			handl_err();
		}
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
