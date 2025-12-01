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

# define HEX_ALPHABET "0123456789ABCDEF"
# define HEX_ALPHABET_LOW "0123456789abcdef"
# define DEC_ALPHABET "0123456789"

/// a single byte for bytewise operations
typedef unsigned char	t_byte;

//! @name Character Classes
//!@{
/** @brief return 0 if c is not a alphanumerical character. */
int		ft_isalnum(int c);

/**  @brief return 0 if c is not a alphabetical character. */
int		ft_isalpha(int c);

/**  @brief return 0 if c is not an ascii character. */
int		ft_isascii(int c);

/**  @brief return 0 if c is not a printable character. */
int		ft_isprint(int c);

/**  @brief return 0 if c is not a digit character. */
int		ft_isdigit(int c);

/**  @brief return uppercase version of c, if c is a lowercase character. */
int		ft_toupper(int c);
int		ft_tolower(int c);
//!@}

//! @name memory
//!@{

/**  @brief set n bytes starting from s with c as character */
void	*ft_memset(void *s, int c, size_t n);

/**  @brief set n bytes starting from s with 0 */
void	ft_bzero(void *s, size_t n);

/**  @brief copy n bytes from src to dest, undefined behaviour with overlapping pointers. */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**  @brief move n bytes from src to dest, handles overlapping pointers. */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**  @brief find pointer with value of c within n bytes starting from s. */
void	*ft_memchr(const char *s, int c, size_t n);

/**  @brief compare s1 and s2 with in n bytes. */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**  @brief alloc a zeroed out memory for an array of n elements with a size of `size` */
void	*ft_calloc(size_t n, size_t size);
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
 */
typedef struct s_iol_el
{
	char *buffer;
	size_t		size;
 /** `free` is optional callback, that triggers when freeing the struct via ft_io_del(). */
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

//! @name buffer list, basic get_next_line is written on this
//!@{

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/** @brief wrapper of a buffer, together with its size; */
typedef struct s_buf
{
	size_t				size;
	t_byte				*p;
}						t_buf;


/** @brief create a new buffer with a given size and allocate a buffer for it. */
t_buf					*ft_buf_new(size_t size);

/** @brief create a max BUFFER_SIZE buffer from a file descriptior fd. */
t_buf					*ft_buf_read(int fd);

/**
 * @brief to split buffer at a given pointer in it into 2 buffers.
 * the return value is the part to the left,
 * and the given pointer will be the last position of the it.
 * and the buffer 'b' will the one on the left of the index.
 */
t_buf					*ft_buf_split(t_buf **b, size_t left_len);

/** @brief concat to buffers together and frees the inputs */
t_buf					*ft_buf_cat(t_buf **left, t_buf **right);

/** @brief frees the memory of the given pointer and sets the address of it to NULL */
void					ft_buf_free(t_buf **b);

/** @brief turn a buffer struct into a zero index c string */
char					*ft_buf_str(t_buf **b);

/** @brief copy a buffer from src to dest, basically cloning it */
void					ft_buf_cp(t_buf *src, t_buf *dest);

/** @brief find the first occurence of any bytes in args (null terminated string) */
t_byte					*ft_buf_chr(t_buf *b, t_byte *args);
//!@}

#endif
