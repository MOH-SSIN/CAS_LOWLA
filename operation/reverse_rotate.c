#include "../push_swap.h"

static void reverse_rotate(t_noeud **pile)
{
    t_noeud *last;
    t_noeud *before_last;

    if (!(*pile) || !(*pile)->suivant)
        return ;

    last = *pile;
    while (last->suivant)
        last = last->suivant;

    before_last = last->precedent;

    before_last->suivant = NULL;
    last->precedent = NULL;


    last->suivant = *pile;
    (*pile)->precedent = last;
    *pile = last;
}

void rra(t_noeud **a, bool afch)
{
    reverse_rotate(a);
    if (!afch)
        write(1, "rra\n", 4);
}

void rrb(t_noeud **b, bool afch)
{
    reverse_rotate(b);
    if (!afch)
        write(1, "rrb\n", 4);
}

void rrr(t_noeud **a, t_noeud **b, bool afch)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (!afch)
        write(1, "rrr\n", 4);
}