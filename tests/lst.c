/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:32:56 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/21 21:09:00 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/srgalan/Sync/git-ft/datalib/datalib.h"

void	status(char *msg, t_list *lst, unsigned int spc)
{
	unsigned int	i;

	i = 0;
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\t`", 1);
	ll_print(lst);
	ft_putchar_fd('`', 1);
	while (i++ < spc)
		ft_putchar_fd('\n', 1);
}

void	test_addition(t_list **list)
{
	t_list	*tmp;

	status("**Sea la lista:**", *list, 2);
	ll_add_first(list, ll_new("antgalan"));
	status("Se añade 'antgalan' al principio:", *list, 1);
	ll_add_first(list, ll_new("ernesmar"));
	status("Se añade 'ernesmar' al principio:", *list, 2);
	ll_add_after(ll_search(*list, "ernesmar"), ll_new("yfuentes"));
	status("Se añade 'yfuentes' después de 'ernesmar':", *list, 1);
	ll_add_after(ll_search(*list, "antgalan"), ll_new("abello-r"));
	status("Se añade 'abello-r' después de 'antgalan':", *list, 2);
	ll_add_last(list, ll_new("pmarquez"));
	status("Se añade 'pmarquez' al final:", *list, 3);
	tmp = NULL;
	status("**Sea la lista (constante):**", tmp, 2);
	ll_add_first(&tmp, ll_new("antgalan"));
	status("Se añade 'antgalan' al principio:", tmp, 2);
	tmp = NULL;
	ll_add_last(&tmp, ll_new("antgalan"));
	status("Se añade 'antgalan' al final:", tmp, 2);
	tmp = NULL;
	ll_add_after(ll_search(tmp, "antgalan"), ll_new("abello-r"));
	status("Se añade 'abello-r' después de 'antgalan':", tmp, 4);
}

void	test_stats(t_list *list)
{
	ll_add_after(ll_search(list, "yfuentes"), ll_new("ernesmar"));
	status("**Sea la lista:**", list, 2);
	ft_putstr_fd("El primer elemento:\t", 1);
	if (ll_first(list))
		ft_putendl_fd(ll_first(list)->content, 1);
	else
		ft_putendl_fd("No existe", 1);
	ft_putstr_fd("El último elemento:\t", 1);
	if (ll_last(list))
		ft_putendl_fd(ll_last(list)->content, 1);
	else
		ft_putendl_fd("No existe", 1);
	ft_putstr_fd("\n¿Está 'antgalan'?:\t", 1);
	if (ll_search(list, "antgalan"))
		ft_putendl_fd("Sí", 1);
	else
		ft_putendl_fd("No", 1);
	ft_putstr_fd("¿Está 'sr-galan'?:\t", 1);
	if (ll_search(list, "srgalan"))
		ft_putendl_fd("Sí", 1);
	else
		ft_putendl_fd("No", 1);
	ft_putstr_fd("\n\n\n", 1);
}

void	test_deletion(t_list **list)
{
	t_list	*tmp;

	status("**Sea la lista:**", *list, 2);
	ll_purge(list, "ernesmar");
	status("Se purga *ernesmar*:", *list, 1);
	ll_remove_first(list);
	status("Se elimina el primer elemento:", *list, 1);
	ll_remove_last(list);
	status("Se elimina el último elemento:", *list, 1);
	ll_remove(list, ll_search(*list, "abello-r"));
	status("Se elimina 'abello-r':", *list, 2);
	tmp = NULL;
	status("Sea la lista (constante):", tmp, 2);
	ll_remove_first(&tmp);
	status("Se elimina el primer elemento:", tmp, 1);
	ll_remove_last(&tmp);
	status("Se elimina el último elemento:", tmp, 1);
	ll_remove(&tmp, ll_search(tmp, "abello-r"));
	status("Se elimina 'abello-r':", tmp, 2);
}

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_putstr_fd("# Funciones de creación\n\n", 1);
	test_addition(&list);
	ft_putstr_fd("# Funciones de estadísticas\n\n", 1);
	test_stats(list);
	test_stats(NULL);
	ft_putstr_fd("# Funciones de eliminación\n\n", 1);
	test_deletion(&list);
}
