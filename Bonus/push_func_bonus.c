/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:32:26 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/10 21:03:50 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (*stack_a)
		push_from_to(stack_a, stack_b);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
		push_from_to(stack_b, stack_a);
}
