/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/17 08:09:02 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

#define HEX_ALPHABET "0123456789ABCDEF"
#define HEX_ALPHABET_LOW "0123456789abcdef"
#define DEC_ALPHABET "0123456789"

/// a single byte for bytewise operations
typedef unsigned char	t_byte;

//! @name Character Classes
//!@{
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);
//!@}

//! @name memory
//!@{
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const char *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
//!@}

//! @name string
//!@{
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);

char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);

/**
 * @brief convert an int to a decimal ascii string 
 */
char	*ft_itoa(int n);

/**
 * @brief convert a long to a decimal ascii string 
 */
char	*ft_ltoa(long n);

/**
 * @brief unsigned convert a long to a decimal ascii string 
 */
char	*ft_ultoa(unsigned long n);

void ft_btoa(t_byte byte, char *target);

/**
 * @brief convert a ptr to a hex ascii string
 */
char *ft_ptoa(void *ptr);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//!@}

//! @name string format
//!@{

// worst doc ever
/**
 * @brief you know what a printf does, come on
 */
int ft_printf(const char *, ...);
//!@}

//! @name IO
//!@{
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//!@}

//! @name linked list
//!@{

//! one link of a linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief create a new list
 */
t_list **ft_lststart(t_list *head);

/**
 * @brief create a new node
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief create a new node
 */
void	ft_lstadd_front(t_list **lst, t_list *new_l);

/**
 * @brief get the length of the list
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief get the last element of a list
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief append a node to a list
 */
void	ft_lstadd_back(t_list **lst, t_list *new_l);

/**
 * @brief remove first element of list
 * @param del function to free content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief append a node to a list
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief apply function to each element of a list
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief apply function to each element and create new list out of the function returns
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief fold function to each element into one value
 */
void *ft_lstfold(t_list *lst, void *acc, void *(*f)(void *, void *));

//!@}

//! @name io list
//!@{

/**
 * @brief represent one part of an io list, these are chained together to in a linked list.
 * @field free should _only_ decide if the *buffer* needs freeing.
 */
typedef struct s_iol_el
{
	char *buffer;
	size_t		size;
	void (*free)(struct s_iol_el*);
}				t_iol_el;

//! @brief pretty prints out an io list to stdout
void ft_iol_pp(t_list *l);

//! @brief pretty prints out one element of an io list to stdout
void ft_iol_pp_el(t_iol_el *el);

/**
 * @brief write one io list to a fd
 */
int ft_iol_write(t_list *l, int fd);


/**
 * @brief free an io list, calls ´iel->free´ to free the buffer to see if 
 */
void ft_iol_del(t_list **l);


//!@}
#endif
