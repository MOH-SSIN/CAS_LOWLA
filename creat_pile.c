#include "push_swap.h"

t_noeud *lstnew(char *args, int indice)
{
    t_noeud *new;

    new = NULL;
    new = (t_noeud *)malloc(sizeof(t_noeud));
    if (!new)
        return (NULL);
    new->indice = indice;
    new->valeur = ft_atoi(args);
    new->length = 1;
    new->appartient = false;
    new->noeud_cible = NULL;
    new->suivant = NULL;
    new->precedent = NULL;
    return (new);
}

t_noeud *lslast(t_noeud *last)
{   
    if (!last)
        return (NULL);
    while (last->suivant)
        last = last->suivant;
    return (last); 
}

void lsadd_back(t_noeud **pile, t_noeud *new)
{
    t_noeud *last;

    if (!new)
        return ;
    if (!*pile)
        *pile = new;
    else
    {
        last = *pile;
        last = lslast(*pile);
        last->suivant = new;
        new->precedent = last;
    }
}



t_noeud *ajouter_noeud(char **args)
{
    t_noeud *pile;
    int     i;

    i = 0;
    pile = NULL;
    while (args[i])
    {
        lsadd_back(&pile ,lstnew(args[i], i));
        i++;
    }
    if (pile_trie(pile))
    {
        liberer_erreurs(args);
        free_pile(pile);
        exit(0);
    }
    ft_lis(&pile);
    liberer_erreurs(args);
    return (pile);
}







