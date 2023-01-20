#include "/home/srgalan/Sync/git-ft/datalib/datalib.h"

void	status(char *msg, t_set *set)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Set: ", 1);
	set_print(set);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Size: ", 1);
	ft_putnbr_fd(set_size(set), 1);
	ft_putstr_fd("\n\n", 1);
}

// Los estudiantes contienen usuarios repetidos.
// Los miembros del STAFF son usuarios únicos.
void	test_addition(t_set **e, t_set **s)
{
	set_add(e, "antgalan");
	set_add(e, "agalan-h");
	set_add(e, "ernesmar");
	set_add(e, "begarijo");
	set_add(e, "abello-r");
	set_add(e, "dimolina");
	set_add(e, "ernmarti");
	set_add(e, "ernesmar");
	set_add(e, "lagarcia");
	set_add(e, "cherrero");
	set_add(e, "pmarquez");
	set_add(e, "antgalan");
	status("[Cursus] > Se añaden algunos cursus.", *e);
	set_add(s, "QUERO");
	set_add(s, "CERBERO");
	set_add(s, "abello-r");
	set_add(s, "STEAMO");
	set_add(s, "SIRIUS");
	set_add(s, "LEDESMA");
	set_add(s, "MEDUSA");
	set_add(s, "lagarcia");
	set_add(s, "MINA");
	set_add(s, "CATARSIS");
	set_add(s, "pmarquez");
	status("[STAFF] > Se añaden los miembros del STAFF.", *s);
	ft_putchar_fd('\n', 1);
}

// Se eliminan los usuarios que no han sido estudiantes del Cursus.
void	test_deletion(t_set **set)
{
	set_remove(set, "agalan-h");
	set_remove(set, "ernmarti");
	set_remove(set, "agalan-h");
	status("[Cursus] > Se eliminan los que no son del Cursus.", *set);
	ft_putchar_fd('\n', 1);
}

// Se opera con los conjuntos de estudiantes y STAFF.
void	test_operations(t_set *a, t_set *b)
{
	status("[Unión] > Son estudiantes O son STAFF.", set_union(a, b));
	status("[Intersección] > Son estudiantes Y son STAFF.", set_intersection(a, b));
	status("[Diferencia] > Son estudiantes Y NO son STAFF.", set_difference(a, b));
	status("[Diferencia] > Son STAFF Y NO son estudiantes.", set_difference(b, a));
	ft_putstr_fd("Y ahora suponiendo que uno de los conjuntos es vacío.\n\n", 1);
	status("[Unión] > Son estudiantes O son {}.", set_union(a, NULL));
	status("[Intersección] > Son {} Y son STAFF.", set_intersection(NULL, b));
	status("[Diferencia] > Son {} Y NO son STAFF.", set_difference(NULL, b));
	status("[Diferencia] > Son STAFF Y NO son {}.", set_difference(b, NULL));
	ft_putchar_fd('\n', 1);
}

void	test_stats(t_set *a, t_set *b)
{
	t_set	*i;

	i = set_intersection(a, b);
	status("[Pertenencia] > ¿Este conjunto es subconjunto de STAFF?", i);
	ft_putstr_fd("\tRespuesta: ", 1);
	ft_putstr_fd(set_subset(i, b) ? "Sí." : "No.", 1);
	ft_putstr_fd("\n\n", 1);
	status("[Pertenencia] > ¿Este conjunto es subconjunto de {}?", i);
	ft_putstr_fd("\tRespuesta: ", 1);
	ft_putstr_fd(set_subset(i, NULL) ? "Sí." : "No.", 1);
	ft_putchar_fd('\n', 1);
	status("[Pertenencia] > ¿Este conjunto es subconjunto de Cursus?", NULL);
	ft_putstr_fd("\tRespuesta: ", 1);
	ft_putstr_fd(set_subset(NULL, a) ? "Sí." : "No.", 1);
	ft_putchar_fd('\n', 1);
	status("[Igualdad] > ¿Los conjuntos Cursus y STAFF son iguales?", NULL);
	ft_putstr_fd("\tRespuesta: ", 1);
	ft_putstr_fd(set_equal(a, b) ? "Sí." : "No.", 1);
	ft_putchar_fd('\n', 1);
	status("[Igualdad] > ¿Los conjuntos {} y {} son iguales?", NULL);
	ft_putstr_fd("\tRespuesta: ", 1);
	ft_putstr_fd(set_equal(NULL, NULL) ? "Sí." : "No.", 1);
	ft_putchar_fd('\n', 1);
	status("[Igualdad] > ¿Los conjuntos Cursus y {} son iguales?", NULL);
	ft_putstr_fd("\tRespuesta: ", 1);
	ft_putstr_fd(set_equal(a, NULL) ? "Sí." : "No.", 1);
	ft_putchar_fd('\n', 1);
}

// Main function.
int	main(void)
{
	t_set	*cursus;
	t_set	*staff;

	cursus = NULL;
	staff = NULL;
	status("[Cursus] > Se crea el conjunto.", cursus);
	status("[STAFF] > Se crea el conjunto.", staff);
	ft_putchar_fd('\n', 1);
	test_addition(&cursus, &staff);
	test_deletion(&cursus);
	test_operations(cursus, staff);
	test_stats(cursus, staff);
	return (0);
}
