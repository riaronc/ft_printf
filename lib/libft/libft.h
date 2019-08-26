/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odushko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:49:13 by odushko           #+#    #+#             */
/*   Updated: 2019/03/24 17:23:08 by odushko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);

int					ft_memcmp(const void *arr1, const void *arr2, size_t num);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, void *src, int c, size_t num);
void				*ft_memchr(const void *arr, int c, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memset(void *b, int c, size_t len);

char				*ft_strnew(size_t size);
char				*ft_strchr(const char *str, int ch);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t num);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *str, int len);
char				*ft_strncat(char *dest, const char *app, size_t n);
char				*ft_strcat(char *dest, const char *app);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t num);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dest, const char *src, size_t num);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t num);

void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));

int 				ft_atoi_base(const char *str, int base, int upper);
__int128_t			ft_atoi(const char *s);
char				*ft_itoa(__int128_t n);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);

#endif
