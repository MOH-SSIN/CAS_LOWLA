#include "../push_swap.h"

static void push(t_noeud **src, t_noeud **dest)
{
    t_noeud *first;

    if (!(*src))
        return ;

    first = *src;
    *src = first->suivant; 

    if (*src)
        (*src)->precedent = NULL;

    first->suivant = *dest;

    if (*dest)
        (*dest)->precedent = first;

    first->precedent = NULL;
    *dest = first;
}

void pa(t_noeud **a, t_noeud **b, bool afch)
{
    push(b, a);
    if (!afch)
        write(1, "pa\n", 3);
}

void pb(t_noeud **a, t_noeud **b, bool afch)
{
    push(a, b);
    if (!afch)
        write(1, "pb\n", 3);
}
// pa(&a, &b, false); → déplace le premier élément de b vers a.
// pb(&a, &b, false); → déplace le premier élément de a vers b.
