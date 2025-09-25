/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:29:53 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/12 15:40:28 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack;
	while (tmp1)
	{
		tmp1 -> index = 1;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp1 -> content > tmp2 -> content)
				tmp1 -> index += 1;
			tmp2 = tmp2 -> next;
		}
		tmp1 = tmp1 -> next;
	}
}

int	ft_get_high_index(t_list *stack)
{
	t_list	*tmp;
	int		high;

	tmp = stack;
	high = tmp->index;
	while (tmp)
	{
		if (tmp->index > high)
			high = tmp->index;
		tmp = tmp->next;
	}
	return (high);
}

int	find_high_index(t_list **stack_b, int high)
{
	t_list	*tmp;
	int		it;
	int		size;

	size = ft_lstsize(*stack_b);
	tmp = *stack_b;
	it = 0;
	while (tmp && it < size / 2)
	{
		if (tmp->index == high)
			return (1);
		tmp = tmp->next;
		it++;
	}
	return (0);
}
