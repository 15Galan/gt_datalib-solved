/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datalib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/30 16:16:50 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATALIB_H
# define DATALIB_H

# include <stdlib.h>
# include <unistd.h>
# include "dll.h"
# include "cdll.h"

/** GENERAL PURPOSE	**/

int		len(void *data);

/**	QUEUE	**/

// Struct for the elements of the queue.
typedef struct s_queue
{
	void			*data;
	struct s_queue	*next;
}	t_queue;

// Basic operations.
t_queue	*que_new(void *data);
void	que_enqueue(t_queue **queue, void *data);
void	*que_dequeue(t_queue **queue);
void	que_clear(t_queue **queue);

// Check some data from the queue.
int		que_empty(t_queue *queue);
int		que_size(t_queue *queue);
t_queue	*que_first(t_queue *queue);
t_queue	*que_last(t_queue *queue);

// Print the queue.
void	que_print(t_queue *queue);

/**	STACK	**/

// Struct for the elements of the stack.
typedef struct s_stack
{
	void			*data;
	struct s_stack	*next;
}	t_stack;

// Basic operations.
t_stack	*stk_new(void *data);
void	stk_push(t_stack **stack, void *data);
t_stack	*stk_pop(t_stack **stack);
void	stk_clear(t_stack **stack);

// Check some data from the stack.
int		stk_empty(t_stack *stack);
int		stk_size(t_stack *stack);
t_stack	*stk_top(t_stack *stack);
void	*stk_peek(t_stack *stack);

// Print the stack.
void	stk_print(t_stack *stack);

/** SET **/

// Struct for the elements of the set.
typedef struct s_set
{
	void			*data;
	struct s_set	*next;
}	t_set;

// Basic operations.
t_set	*set_new(void *data);
void	set_add(t_set **set, void *data);
void	set_remove(t_set **set, void *data);
void	set_clear(t_set **set);

// Math operations.
t_set	*set_union(t_set *set1, t_set *set2);
t_set	*set_inter(t_set *set1, t_set *set2);
t_set	*set_diff(t_set *set1, t_set *set2);

// Check some data from the set.
int		set_empty(t_set *set);
int		set_contains(t_set *set, void *data);
int		set_subset(t_set *set1, t_set *set2);
int		set_equal(t_set *set1, t_set *set2);
int		set_size(t_set *set);

// Print the set.
void	set_print(t_set *set);

#endif