/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <fkruger@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 04:56:24 by fkruger           #+#    #+#             */
/*   Updated: 2025/10/29 04:56:26 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *result;
  void *new_content;

  if (lst == NULL)
    return (NULL);
  new_content = f(lst->content);
  result = ft_lstmap(lst->next, f, del);
  ft_lstadd_front(&result, ft_lstnew(new_content));
  return (result);
}
