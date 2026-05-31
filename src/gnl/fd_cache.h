/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_cache.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:58:42 by fkruger           #+#    #+#             */
/*   Updated: 2026/04/23 17:58:42 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns a char string with max size BUFFER_SIZE assigned to fd in earlier calls
// if fd is not yet associated with an buffer, new is called to create it
void	*fdc_at(int fd, void *(*new)(void));

void	fdc_free(int fd);
void	fdc_free_all(void);

void	*fdc_pop(int fd);
void	*fdc_add(int fd, void *buffer);
