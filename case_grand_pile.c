#include "push_swap.h"

static bool is_true(t_noeud *a)
{
    while (a)
    {
        if (a->appartient == false)
            return (1);
        a = a->suivant;
    }
    return (0);
}


void push_non_list(t_noeud **a, t_noeud**b)
{
    t_noeud *tmp;

    while (is_true(*a))
    {
        set_moins_cher(*a);
        tmp = *a;
        tmp = *a;
        if ((tmp)->appartient)
            ra(a, false);
        else
            pb(a, b, false);
        tmp = (tmp)->suivant;
    }
}

static  t_noeud*ft_Get_PtitdNode(t_noeud *a)
{
    t_noeud *ptit_valeur;
    
    if (!a)
        return (NULL);
    ptit_valeur = a;
    while (a)
    {
        if (a->valeur < ptit_valeur->valeur)
            ptit_valeur = a;
        a =a->suivant;
    }
    return (ptit_valeur);
}

void case_grand_pile(t_noeud **a,t_noeud **b)
{
    t_noeud *ptit;
    // afficher_sub_ptr(*a);
    push_non_list(a,b);
    while (*b)
    {
        init_pile(a,b);
        move_b_vers_a(a,b);
    }
    ptit = ft_Get_PtitdNode(*a);
    if (ptit->au_dessus_median)
        while (ptit->indice)
            ra(a, false);
    else
        while (ptit->indice)
            rra(a, false);
    // afficher_sub_ptr(*a);
}
