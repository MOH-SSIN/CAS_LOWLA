#include "push_swap.h"


void    set_moins_cher(t_noeud *pile)
{
    int taille;
    t_noeud *head;

    taille = pile_taile(pile);
    head = pile;
    while (head)
    {
        if (head->indice <= (taille / 2))
            head->moins_cher = true;
        else
            head->moins_cher = false;
        head = head->suivant;
    }
}


void    set_node_cible(t_noeud *a, t_noeud *b)
{
    t_noeud *target_node;
    t_noeud *current_node;
    long    max_indx;

    while (b)
    {
        max_indx = LONG_MAX;
        current_node = a;
        while (current_node)
        {
            if (current_node->valeur < max_indx && current_node->valeur > b->valeur)
            {
                target_node = current_node;
                max_indx = current_node->valeur;
            }
            current_node = current_node->suivant;
        }
        if (max_indx == LONG_MAX)
            b->noeud_cible = small_node(a);
        else
            b->noeud_cible = target_node;
        b = b->suivant;
    }
}

void    set_push_price(t_noeud *a, t_noeud *b)
{
    int len_a;
    int len_b;

    len_a = lenght_stack(a);
    len_b = lenght_stack(b);
    while (b)
    {
        b->push_price = b->indice;
        if (!b->au_dessus_median)
            b->push_price = len_b - b->indice;
        if (b->noeud_cible->au_dessus_median)
            b->push_price += b->noeud_cible->indice;
        else
            b->push_price += len_a - b->noeud_cible->indice;
        b = b->suivant;
    }
}

void    set_cheapest(t_noeud *b)
{
    int     cheap_price;
    t_noeud *test;

    if (!b)
        return ;
    cheap_price = b->push_price + 1;
    test = b;
    while (b)
    {
        if (b->push_price < cheap_price)
        {
            test->moins_cher = false;
            test = b;
            b->moins_cher = true;
            cheap_price = b->push_price;
        }
        else
            b->moins_cher = false;
        b = b->suivant;
    }
}

void init_pile(t_noeud **a, t_noeud **b)
{
    set_node_cible(*a, *b);
    set_moins_cher(*a);
    set_moins_cher(*b);
    set_push_price(*a, *b);
    set_cheapest(*b);
}