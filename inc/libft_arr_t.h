#ifndef LIBFT_ARR_T_H
# define LIBFT_ARR_T_H

typedef void		*t_arr_el;
// typedef void	*arr_t;
typedef t_arr_el	*t_arr;

typedef t_arr_el	(*t_arr_scal)(t_arr_el el);
typedef void		*(*t_arr_fold)(void *acc, t_arr_el el);
#endif
