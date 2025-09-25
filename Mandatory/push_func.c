/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:32:26 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/18 17:54:02 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_patterns_check2(t_list *stack, int peak, int up, int direction)
{
	int	len;

	len = ft_lstsize(stack);
	while (stack && (stack)->next)
	{
		if ((stack)->index < (stack)->next->index)
		{
			if (direction == DOWN)
				return (RA);
			up++;
			direction = UP;
		}
		else
		{
			if (direction == UP)
				peak = 1;
			direction = DOWN;
		}
		(stack) = (stack)->next;
	}
	if (peak && (up > len / 4))
		return (RRA);
	return (RA);
}

int	ft_patterns_check(t_list *stack)
{
	int		peak;
	int		down;
	int		up;
	int		direction;
	t_list	*tmp;

	peak = 0;
	down = 0;
	up = 0;
	direction = 0;
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			down++;
		tmp = tmp->next;
	}
	if (down > (ft_lstsize(stack) - 1) * 0.7)
		return (RRA);
	return (ft_patterns_check2(stack, peak, up, direction));
}

void	push_to_stack_b(t_list **stack_a, t_list **stack_b, int del)
{
	int	i;
	int	sens;

	i = 0;
	sens = ft_patterns_check(*stack_a);
	while (ft_lstsize(*stack_a) > 0)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (del + i))
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
			i++;
		}
		else if (sens)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
	}
}

void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	high_idx;

	high_idx = ft_get_high_index(*stack_b);
	while (0 < ft_lstsize(*stack_b))
	{
		if ((*stack_b)->index == high_idx)
		{
			ft_pa(stack_a, stack_b);
			high_idx--;
		}
		else if ((*stack_b)->next->index == high_idx)
		{
			ft_sb(stack_b);
			ft_pa(stack_a, stack_b);
			high_idx--;
		}
		else
		{
			if (find_high_index(stack_b, high_idx))
				ft_rb(stack_b);
			else
				ft_rrb(stack_b);
		}
	}
}
