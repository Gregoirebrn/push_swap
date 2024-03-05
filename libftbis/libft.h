/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:08 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/01 19:42:47 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_pile
{
	void			*content;
	int				rank;
	struct s_pile	*next;
}	t_pile;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
long	ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_pile	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_pile **lst, t_pile *new);
int		ft_lstsize(t_pile *lst);
t_pile	*ft_lstlast(t_pile *lst);
void	ft_lstadd_back(t_pile **lst, t_pile *new);
void	ft_lstdelone(t_pile *lst, void (*del)(void *));
void	ft_lstclear(t_pile **lst, void (*del)(void *));
void	ft_lstiter(t_pile *lst, void (*f)(void *));
t_pile	*ft_lstmap(t_pile *lst, void *(*f)(void *), void (*del)(void *));

size_t	ft_ctofindinstr(char *str, char c);
char	*get_next_line(int fd);
char	*ft_strcut(char *str);
char	*ft_strnext_line(char *str);
char	*ft_lastline(char *str);
char	*ft_freenjoin(char *s1, char *s2);
#endif