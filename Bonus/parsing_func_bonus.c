/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_func_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:31:05 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/11 22:44:08 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**args_spliter(int argc, char **argv)
{
	int		x;
	char	*s;
	char	**tmp;

	x = 1;
	s = ft_strdup("");
	if (!s)
		handl_err_and_free(&s);
	while (x < argc)
	{
		s = ft_strjoin(s, argv[x++]);
		if (!s)
			handl_err_and_free(&s);
		s = ft_strjoin(s, " ");
		if (!s)
			handl_err_and_free(&s);
	}
	tmp = ft_split(s, ' ');
	free(s);
	return (tmp);
}

int	ft_check_digit(char **argv)
{
	int	x;
	int	y;

	x = 0;
	while (argv[x])
	{
		y = 0;
		while (argv[x][y])
		{
			if (ft_is_digit(argv[x][y]) == 0 && argv[x][0] != '-'
					&& argv[x][0] != '+')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_check_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	create_stack(t_list **stack_a, char **argv)
{
	int		i;
	t_list	*new;

	i = 0;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
			return (0);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}

int	ft_parcing(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 0;
	if (ft_check_sp_end(argc, argv) == 0)
		return (0);
	argv = args_spliter(argc, argv);
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (!ft_nmbr_range(argv[i]))
		{
			ft_free(argv);
			return (0);
		}
		i++;
	}
	if (!ft_check_dup(argv) || !ft_check_digit(argv))
	{
		ft_free(argv);
		return (0);
	}
	i = create_stack(stack_a, argv);
	ft_free(argv);
	return (i);
}
