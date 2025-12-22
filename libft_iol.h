/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_iol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 16:51:43 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IOL_H
# define LIBFT_IOL_H

# include "libft_ll.h"
# include <stdlib.h>

//! @name io list
//!@{

typedef t_list	*t_iol;

/**
 * @brief represent one part of an io list,
 * these are chained together to in a linked list.
 */
typedef struct s_iol_el
{
	char		*buffer;
	size_t		size;
	/** `free` is optional callback,
		that triggers when freeing the struct via ft_io_del(). */
	void		(*free)(struct s_iol_el *);
}				t_iol_el;

//! @brief create news iol element
t_iol_el		*ft_iol_el_alloc(size_t size);

//! @brief pretty prints out an io list to stdout
void			ft_iol_pp(t_list *l);

//! @append a buffer pointer with a size to an iol */
void			ft_iol_append(t_list **io_l, char *start, size_t size);

//! @brief pretty prints out one element of an io list to stdout
void			ft_iol_pp_el(t_iol_el *el);

/**
 * @brief write one io list to a fd
 */
int				ft_iol_write(t_list *l, int fd);

//! @brief get the total size of all elements summed up
size_t			ft_iol_size(t_list *iol_l);

//! @brief copy an the buffers of an io list into a single string.
char			*ft_iol_str(t_list *iol_l);

size_t			ft_iol_str_l(t_list *iol_l, char *target, size_t length);

//! @brief always free the buffer too, if ft_iol_del is called on the iol.
void			ft_iol_free_always(t_iol_el *el);

/**
 * @brief free an io list, calls ´iel->free´ to free the buffer to see if
 */
void			ft_iol_del(t_list **l);

//!@}
#endif
