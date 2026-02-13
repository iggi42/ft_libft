/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_arr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:32:03 by fkruger           #+#    #+#             */
/*   Updated: 2025/12/05 16:51:43 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARR_H
# define LIBFT_ARR_H
# include <stddef.h>
# include <stdlib.h>

void	**ft_arr_new(size_t size);
size_t	ft_arr_len(void *arr);
void	ft_arr_neach(void *arr, apply);

#endif
