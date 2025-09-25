/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:27:21 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/12 12:33:59 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_is_digit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	num;
	int				s;

	num = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			s *= -1;
	while (*str >= '0' && *str <= '9')
	{
		if (num * 10 + *str - '0' > LONG_MAX)
			return (-(s + 1) / 2);
		num = num * 10 + *str++ - '0';
	}
	return ((int )num * s);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (dst == src)
		return (dst);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
