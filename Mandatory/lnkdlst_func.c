/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnkdlst_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:30:08 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/18 14:56:53 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new) //needs to edit
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstnew(int content, int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = i;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst)
	{
		ptr = ft_lstlast(*lst);
		if (ptr)
		{
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst ->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
