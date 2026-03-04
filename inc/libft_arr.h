/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_arr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:04 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARR_H
# define LIBFT_ARR_H
# include "libft_arr_t.h"
# include <stddef.h>

arr_t			*ft_arr_new(size_t size);
size_t			ft_arr_len(arr_t arr);

// call 'apply' against each element of the array
void			ft_arr_each(arr_t arr, void (*apply)(void *));
void			ft_arr_neach(arr_t arr, size_t n, void (*apply)(void *));

// fold (from lower to higher index) over the given array
// void* fold(void *acc, void *arr_el)
void			*ft_arr_fold(arr_t arr, void *(*fold)(void *, void *), void *acc);

#endif
