/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_modification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/08 14:46:49 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

/**
 * @brief	Creates a new element for the stack.
 *
 * @param data	The data to store in the element.
 *
 * @return	Pointer to the new element.
 */
t_stack	*sk_new(void *data)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

/**
 * @brief	Adds an element to the stack.
 *
 * @param stack	Pointer to the stack.
 * @param data 	The data to store in the new element.
 */
void	sk_push(t_stack **stack, void *data)
{
	t_stack	*new;

	new = sk_new(data);
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

/**
 * @brief	Extracts the top element from the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return 	Pointer to the top element;
 * 			NULL if the stack is empty.
 */
t_stack	*sk_pop(t_stack **stack)
{
	t_stack	*aux;

	if (*stack == NULL)
		return (NULL);
	aux = *stack;
	*stack = (*stack)->next;
	aux->next = NULL;
	return (aux);
}

/**
 * @brief	Deletes the stack.
 *
 * @param stack 	Pointer to the stack.
 */
void	sk_clear(t_stack **stack)
{
	t_stack	*aux;

	while (*stack != NULL)
	{
		aux = *stack;
		*stack = (*stack)->next;
		free(aux);
	}
}
