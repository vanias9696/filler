/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:16:21 by ismus             #+#    #+#             */
/*   Updated: 2017/10/25 19:16:23 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int a);
/*
**alphabet or number
*/
int					ft_isalpha(int a);
/*
**alphabet
*/
int					ft_isascii(int c);
/*
**ascii
*/
int					ft_isdigit(int c);
/*
**digit
*/
int					ft_isprint(int c);
/*
**32...127
*/
int					ft_strcmp(const char *s1, const char *s2);
/*
**compare s1 ans s2
*/
char				*ft_strdup(const char *src);
/*
**removes memory and copies c
*/
size_t				ft_strlen(const char *c);
/*
**length с
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/*
**compare s1 ans s2 first n symbols
*/
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
/*
**first entry into the line in first len symbols
*/
char				*ft_strstr(char *str1, char *str2);
/*
**first entry into the line
*/
int					ft_tolower(int c);
/*
**do low
*/
int					ft_toupper(int c);
/*
**do  up
*/
char				*ft_strcpy(char *str1, const char *str2);
/*
**copy str2 in str1
*/
char				*ft_strncpy(char *str1, const char *str2, size_t n);
/*
**first n symbols copy str2 in str1
*/
void				*ft_memset(void *b, int c, size_t n);
/*
**first n byte memory will be c
*/
void				*ft_memcpy (void *dest, const void *s, size_t n);
/*
**first n byte memory will be s
*/
void				*ft_memccpy(void *dest, const void *s, int c, size_t n);
/*
**first n bite memory will be s until the symbol is met
*/
void				*ft_memmove(void *dest, const void *s, size_t n);
/*
**also copies the intersecting lines
*/
void				*ft_memchr(const void *t, int c, size_t n);
/*
**looking for the first entry c in first n bytes
*/
int					ft_memcmp(const void *ar1, const void *ar2, size_t n);
/*
**compare s1 ans s2 first n bytes
*/
void				ft_bzero(void *s, size_t n);
/*
**fills with zeros
*/
char				*ft_strcat(char *dest, const char *src);
/*
**combining rows
*/
char				*ft_strncat(char *dest, const char *src, size_t n);
/*
**combining rows, first n src
*/
char				*ft_strchr(const char *str, int s);
/*
**return first founded s symbol
*/
char				*ft_strrchr(const char *str, int s);
/*
**return last founded s symbol
*/
int					ft_atoi(const char *str);
/*
**alphabet to int
*/
size_t				ft_strlcat(char *dst, const char *src, size_t size);
/*
**combining rows and return number symbols, which copied
*/

void				ft_putchar(char c);
/*
**write char
*/
void				ft_putstr(char const *s);
/*
**write string
*/
void				ft_putendl(char const *s);
/*
**putstr +\n
*/
char				*ft_itoa(intmax_t n);
/*
**int to alphabet
*/
void				ft_putnbr(int n);
/*
**write number
*/
void				ft_putchar_fd(char c, int fd);
/*
**putchar in fd
*/
void				ft_putstr_fd(char const *s, int fd);
/*
**putstr in fd
*/
void				ft_putendl_fd(char const *s, int fd);
/*
**putendl in fd
*/
void				ft_putnbr_fd(int n, int fd);
/*
**putnbr in fd
*/
char				*ft_strnew(size_t size);
/*
**str in size memory \0
*/
void				ft_strdel(char **as);
/*
**free *as
*/
void				ft_strclr(char *s);
/*
**do all \0
*/
void				ft_striter(char *s, void (*f)(char *));
/*
**Applies f to each character and adress
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/*
**Applies f to each character
*/
char				*ft_strmap(char const *s, char (*f)(char));
/*
**Applies the function f to all symbols return new
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
**Applies the function f to all symbols and adress return new
*/
char				**ft_strsplit(char const *s, char c);
/*
**split c
*/
char				*ft_strtrim(char const *s);
/*
**copy without whitespaces in start and end
*/
char				*ft_strjoin(char const *s1, char const *s2);
/*
**combines and returns s1 + s2
*/
char				*ft_strsub(char const *s, unsigned int start, size_t len);
/*
**in start to start + len copy s to new string
*/
int					ft_strequ(char const *s1, char const *s2);
/*
**if s1 == s2 return 1 else 0
*/
int					ft_strnequ(char const *s1, char const *s2, size_t n);
/*
**first n if s1 == s2 return 1 else 0
*/
void				ft_memdel(void **ap);
/*
**free *ap
*/
void				*ft_memalloc(size_t size);
/*
**allocates memory
*/

t_list				*ft_lstnew(void const *content, size_t size);
/*
**new list
*/
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
/*
** free the link’s memory(first)
*/
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
/*
**frees the memory of this link
*/
void				ft_lstadd(t_list **alst, t_list *new);
/*
**new->next = *alst;
*/
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*
**f for all data list
*/
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
**new list, which has f(lst)
*/
int					ft_while_not_n(char *str, char n);
char				*ft_by_n(int n, char c);
int					ft_copy_unt(char *str1, char *str2, char c);
void				ft_del_first_n(char *str, int n);
char				*ft_strcjoin(char *s, char c, int n);
char				*ft_itoa_base(intmax_t n, int base);
char				*ft_utoa_base(uintmax_t n, int base);

#endif
