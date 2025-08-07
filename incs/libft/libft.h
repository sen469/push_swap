/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:07:55 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/06 14:38:52 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
}	t_lst;

// project
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t number, size_t size);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_lst **lst, t_lst *new_node);
void	ft_lstadd_front(t_lst **lst, t_lst *new_node);
void	ft_lstclear(t_lst **lst, void (*del)(void *));
void	ft_lstdelone(t_lst *lst, void (*del)(void *));
void	ft_lstiter(t_lst *lst, void (*f)(void *));
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));
t_lst	*ft_lstnew(void *content);
int		ft_lstsize(t_lst *lst);
void	*ft_memchr(const void *buf, int c, size_t count);
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *str, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t count);
char	*ft_strnstr(const char *big, const char *small, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_substr(const char *str, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// additional functions
int		ft_strcmp(const char *s1, const char *s2);
int		ft_binary_search(int *vec, int size, int key);
int		ft_lower_bound(int *vec, int size, int key);
int		ft_upper_bound(int *vec, int size, int key);

#endif
