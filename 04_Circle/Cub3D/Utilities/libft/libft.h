/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyuki2 <dohyuki2@student.42Gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:43:14 by dohyuki2          #+#    #+#             */
/*   Updated: 2025/02/01 21:04:38 by dohyuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* str */
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcat(char *dest, char *src, int size);
void	ft_strcpy(char *dest, char *src, int i);
int		ft_strlcpy(char *dest, char *src, int size);
int		ft_strlen(char *str);
char	*ft_strmapi(char *str, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strnstr(char *haystack, char *needle, int size);
char	*ft_strrchr(char *str, int c);
char	*ft_strtrim(char *str, char *set);
char	*ft_substr(char *str, int start, int len);

/* allocate */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/* check */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* conversion */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/* list */
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/* memory */
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

/* fd */
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/* sort */
char	**ft_split(char const *s, char c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* get_next_line */
char	*get_next_line(int fd);
int		gnl_check_enter(char *sol);
char	*gnl_read_file(int fd);
char	*gnl_return_line(char *sol);
char	*gnl_next_line(char *sol);
char	*gnl_join_free(char *sol, char *buf);

#endif
