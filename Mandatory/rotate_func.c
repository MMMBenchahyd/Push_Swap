/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:33:55 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/11 16:45:46 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_func(t_list **stack_ptr)
{
	t_list	*ptr;

	ptr = ft_lstlast(*stack_ptr);
	ptr->next = *stack_ptr;
	*stack_ptr = (*stack_ptr)->next;
	ptr->next->next = NULL;
}

void	ft_ra(t_list **stack_a)
{
	if (!*stack_a)
		return ;
	r_func(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	if (!*stack_b)
		return ;
	r_func(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra (stack_a);
	ft_rb (stack_b);
}
