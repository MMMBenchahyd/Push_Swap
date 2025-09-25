/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:34:48 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/19 16:50:10 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_list *s_a)
{
	if (!s_a)
		return (0);
	while (s_a->next)
	{
		if (s_a->content > s_a->next->content)
			return (0);
		s_a = s_a->next;
	}
	return (1);
}
