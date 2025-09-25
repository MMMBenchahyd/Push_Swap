/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:30:40 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/12 12:31:47 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	follow_inst(char **ptr, t_list **stack_a, t_list **stack_b)
{
	while (*ptr)
	{
		if (!ft_strcmp(*ptr, "sa"))
			ft_sa(stack_a);
		if (!ft_strcmp(*ptr, "sb"))
			ft_sb(stack_b);
		if (!ft_strcmp(*ptr, "ss"))
			ft_ss(stack_a, stack_b);
		if (!ft_strcmp(*ptr, "pa"))
			ft_pa(stack_a, stack_b);
		if (!ft_strcmp(*ptr, "pb"))
			ft_pb(stack_a, stack_b);
		if (!ft_strcmp(*ptr, "ra"))
			ft_ra(stack_a);
		if (!ft_strcmp(*ptr, "rb"))
			ft_rb(stack_b);
		if (!ft_strcmp(*ptr, "rr"))
			ft_rr(stack_a, stack_b);
		if (!ft_strcmp(*ptr, "rra"))
			ft_rra(stack_a);
		if (!ft_strcmp(*ptr, "rrb"))
			ft_rrb(stack_b);
		if (!ft_strcmp(*ptr++, "rrr"))
			ft_rrr(stack_a, stack_b);
	}
}

void	check_inst(char *ptr, char *tmp, t_list **stack_a)
{
	char	**s;
	int		i;

	s = ft_split("sa\n sb\n ss\n ra\n rb\n rr\n rra\n rrb\n rrr\n pa\n pb\n",
			' ');
	if (!s)
	{
		ft_clear(&ptr, tmp);
		free_stack_err(stack_a, stack_a, 1);
	}
	i = 0;
	while (s[i])
	{
		if (!ft_strcmp(s[i], ptr))
			break ;
		i++;
	}
	if (!s[i])
	{
		ft_free(s);
		ft_clear(&ptr, tmp);
		free_stack_err(stack_a, stack_a, 1);
	}
	ptr++;
	ft_free(s);
}

char	**ft_get_inst(t_list **stack_a, char **ptr, char *tmp, int i)
{
	char	*s;
	char	*tmp2;

	while (1)
	{
		s = get_next_line(0, &i);
		if (!s && !i)
			break ;
		if (!s && i)
			free_stack_err(stack_a, stack_a, 1);
		check_inst(s, tmp, stack_a);
		tmp2 = tmp;
		tmp = ft_strjoin_gnl(tmp, s, 0);
		ft_clear(&s, tmp2);
		if (!tmp)
			free_stack_err(stack_a, stack_a, 1);
	}
	ptr = ft_split(tmp, '\n');
	if (!ptr && tmp)
	{
		free(tmp);
		free_stack_err(stack_a, stack_a, 1);
	}
	return (free(tmp), ptr);
}

int	main(int argc, char	**argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**ptr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc != 1)
	{
		if (ft_parcing(argc, argv, &stack_a) == 0)
			free_stack_err(&stack_a, &stack_b, 1);
		ptr = ft_get_inst(&stack_a, NULL, NULL, 0);
		if (ptr)
			follow_inst(ptr, &stack_a, &stack_b);
		if (is_sorted(stack_a) && !ft_lstsize(stack_b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free(ptr);
		free_stack_err(&stack_a, &stack_b, 0);
	}
	return (0);
}
