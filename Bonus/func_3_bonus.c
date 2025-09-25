/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:37:56 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/19 17:05:18 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!ptr)
	{
		free((void *)s1);
		return (NULL);
	}
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	free((void *)s1);
	return (ptr);
}

int	ft_nmbr_range(const char *s)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (*s < '0' || *s > '9')
		return (0);
	while (*s && (*s >= '0' && *s <= '9'))
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
		if ((sign * nbr) > 2147483647 || (sign * nbr) < -2147483648)
			return (0);
	}
	if (*s)
		return (0);
	return (1);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack));
		*stack = tmp;
	}
	*stack = NULL;
}
