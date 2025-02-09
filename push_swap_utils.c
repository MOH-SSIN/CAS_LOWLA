#include "push_swap.h"



int pile_taile(t_noeud *a)
{
    int taille = 0;

    while (a)
    {
        taille++;
        a = a->suivant;
    }
    return (taille);
}


int pile_trie(t_noeud *a)
{
    if (!a || !a->suivant)
        return (1);
    while (a->suivant)
    {
        if (a->valeur > a->suivant->valeur)// ila kan element kbare mn element li ba3do
            return (0);
        a = a->suivant; 
    }
    return (1);
}
