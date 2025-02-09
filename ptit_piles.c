#include "push_swap.h"


static t_noeud *grand_element(t_noeud *a)
{
    t_noeud *temp;
    t_noeud *grand_node;

    temp =  a;
    grand_node = a;

    if (!a)
        return NULL;
    while (temp)
    {
        if(temp->valeur > grand_node->valeur)
            grand_node = temp;
        temp = temp->suivant;
    }
    return grand_node;
}

static void trier_trois(t_noeud **a)
{
    t_noeud * grand_node;
    
    grand_node = grand_element(*a);
    if (!(*a) || !(*a)->suivant->suivant)
        return ;
    if (*a == grand_node)// 30 50 20
        sa(a, false);
    if ((*a)->suivant == grand_node)// 20 30 50
        rra(a, false);
    if((*a)->valeur > (*a)->suivant->valeur)// 20 30 50
        sa(a, false);
}


void case_ptit_piles(t_noeud **a, t_noeud **b)
{
    if (pile_taile(*a) == 2)
        sa(a,false);
    else if(pile_taile(*a) == 3)
        trier_trois(a);
}