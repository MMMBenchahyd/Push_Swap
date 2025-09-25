/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:34:26 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/11 17:03:30 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_func(t_list **ptr)
{
	t_list	*last;

	last = ft_lstlast(*ptr);
	last->next = *ptr;
	while ((*ptr)->next != last)
		*ptr = (*ptr)->next;
	(*ptr)->next = NULL;
	*ptr = last;
}

void	ft_rra(t_list **stack_a)
{
	if (!*stack_a)
		return ;
	rr_func(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	if (!*stack_b)
		return ;
	rr_func(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
