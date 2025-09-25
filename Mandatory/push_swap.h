/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:33:13 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/18 15:37:36 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define RA 0
# define RRA 1
# define UP 1
# define DOWN -1

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_front(t_list **lst, t_list *nw);
t_list	*ft_lstnew(int content, int i);
void	ft_lstadd_back(t_list **lst, t_list *nw);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

void	ft_free(char **s);
char	**ft_split(char const *s, char k);
int		ft_is_digit(int k);
int		ft_atoi(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

int		ft_check_sp_end(int argc, char **argv);
int		ft_nmbr_range(const char *s);
void	ft_free_stack(t_list **stack);

int		ft_get_high_index(t_list *s);
int		find_high_index(t_list **stack_b, int high);//
void	ft_index(t_list *stack);
int		ft_parcing(int argc, char **av, t_list **stack_a);

void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_b, t_list **stack_a);

int		is_sorted(t_list *s_a);
void	ft_sort_3(t_list **stack_a);
void	ft_sort_5(t_list **stack_a, t_list **stack_b);
void	ft_select_sort(t_list **stack_a, t_list	**stack_b);
int		ft_find_min(t_list *stack_a);
void	ft_stack_push(t_list **stack_a, t_list **stack_b, int minimum, int flg);
void	push_to_stack_b(t_list **stack_a, t_list **stack_b, int del);
void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b);
void	handl_err(void);
void	handl_err_and_free(char **c);
#endif
