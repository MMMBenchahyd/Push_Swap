/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:53:43 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/13 23:53:43 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_from_to(t_list **from, t_list **to)
{
	t_list	*ptr;

	ptr = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = ptr;
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
		return ;
	push_from_to(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		return ;
	push_from_to(stack_b, stack_a);
	write(1, "pa\n", 3);
}
