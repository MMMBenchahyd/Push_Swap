/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:33:13 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/14 00:08:06 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_front(t_list **lst, t_list *nw);
t_list	*ft_lstnew(int content);
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
void	free_stack_err(t_list **stack_a, t_list **stack_b, int flg);
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
void	handl_err(void);
void	handl_err_and_free(char **c);

char	*get_next_line(int fd, int *i);
void	*ft_clear(char **p, char *ptr);
char	ft_strchr(char *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2, char c);
size_t	ft_strlen_gnl(char *s, char c);
char	*ft_substr_gnl(char *s, int i_str, char c);

#endif
