#include "push_swap.h"


void set_target_node(t_noeud *a, t_noeud *b)
{
    t_noeud *ptr_a;
    t_noeud *target_node;
    long    match_index;

    while (b)
    {
        match_index = LONG_MAX;
        ptr_a = a;
        while (ptr_a)
        {
            if (ptr_a->valeur > b->valeur
                && ptr_a->valeur < match_index)
            {
                match_index = ptr_a->valeur;
                target_node = ptr_a;
            }
            ptr_a = ptr_a->suivant;
        }
        if (LONG_MAX == match_index)
            b->noeud_cible = ft_Get_PtitdNode(a);
        else
            b->noeud_cible = target_node;
        b = b->suivant;
    }
}

void set_price(t_noeud *a, t_noeud *b)
{
    int taile_a;
    int taile_b;

    taile_a = pile_taile(a);
    taile_b = pile_taile(b);
    while (b)
    {
        b->push_price = b->indice;
        if (!(b->au_dessus_median))
            b->push_price = taile_b - (b->indice);
        if (b->noeud_cible->au_dessus_median)
            b->push_price += b->noeud_cible->indice;
        else
            b->push_price += taile_a - (b->noeud_cible->indice);
        b = b->suivant;
    }
}

void set_cheapest(t_noeud *b)
{
    long    match_valeur;
    t_noeud *match_node;

    if (!b)
        return;
    match_valeur = LONG_MAX;
    while (b)
    {
        if (b->push_price < match_valeur)
        {
            match_valeur = b->push_price;
            match_node = b;
        }
        b = b->suivant;
    }
    match_node->moins_cher = true;
}

void init_pile(t_noeud *a, t_noeud *b)
{
    set_index(a);
    set_index(b);
    set_target_node(a, b);
    set_price(a, b);
    set_cheapest(b);
}