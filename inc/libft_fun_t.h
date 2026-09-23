

#ifndef LIBFT_FUN_T_H
# define LIBFT_FUN_T_H

// time to bring some more fun in this party
# include <stdbool.h>

// iterator (kinda like gnl), returns NULL when it ends,
/// otherwise a pointer to
typedef void	*(*t_fun_iter)(void *iter_state);

// predicate https://en.wikipedia.org/wiki/Predicate_(logic)
// used for filtering thru lists of elements to which a
typedef bool	(*t_fun_check)(void *target);

// returns a pointer to something based on 1 input
// is useful for some enumerable functions
typedef void	*(t_fun_clone(void *input));

// something that does something :3
// very useful
typedef void	*(t_fun_touch(void *target));

/// function for folding algorithms
// so f is a fold
// then (0,1,3), a => f(f(f(a, 0), 1), 3)
typedef void	*(*t_fun_fold)(void *acc, void *el);

#endif
