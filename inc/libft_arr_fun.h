
#ifndef LIBFT_ARR_FUN_H
# define LIBFT_ARR_FUN_H
# include "libft_arr_t.h"
# include "libft_fun_t.h"
# include <stddef.h>

t_arr		*ft_arr_from_iter(t_fun_iter itr, void *iter_arg);

// call 'apply' against each element of the array
void		ft_arr_each(t_arr arr, t_fun_touch for_each_el);

// call 'apply' against the first n elements of the array
//   (ignores NULL terminators and feed them into apply instead).
void		ft_arr_neach(t_arr arr, size_t n, t_fun_touch for_each_el);

t_arr		*ft_arr_map(t_arr input, t_fun_clone map_fun);
t_arr		*ft_arr_nmap(t_arr input, size_t n, t_fun_clone map_fun);

// fold bf(from lower to higher index) over the given array
// void* fold(void *acc, void *arr_el)
void		*ft_arr_fold(t_arr arr, t_fun_fold folder, void *acc);

t_arr_el	*ft_arr_find(t_arr arr, t_fun_check is_result);

#endif
