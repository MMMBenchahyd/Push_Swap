/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:34:48 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/18 15:00:37 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *s_a)
{
	while (s_a->next)
	{
		if (s_a->content > s_a->next->content)
			return (0);
		s_a = s_a->next;
	}
	return (1);
}

void	ft_select_sort(t_list **stack_a, t_list	**stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sa (stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_3(stack_a);
	else if (ft_lstsize(*stack_a) == 5 || ft_lstsize(*stack_a) == 4)
		ft_sort_5(stack_a, stack_b);
	else
	{
		if (ft_lstsize(*stack_a) <= 100)
			push_to_stack_b(stack_a, stack_b, 11);
		else if (ft_lstsize(*stack_a) > 100)
			push_to_stack_b(stack_a, stack_b, 37);
		ft_push_back_to_a(stack_a, stack_b);
	}
}
