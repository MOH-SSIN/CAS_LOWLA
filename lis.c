#include "push_swap.h"


static t_noeud *ft_Get_MaxNoueud_Length(t_noeud *a)
{
    t_noeud * max_node;
    int     max_length;;

    max_node = a;
    max_length = a->length;
    while (a)
    {
        if (a->length > max_length)
        {
            max_length = a->length;
            max_node = a;
        }
        a = a->suivant;
    }
    return (max_node);
}

static void ft_appartient(t_noeud **a)
{
    t_noeud *max_noeudleght;

    // printf("dans la fnction ft_appartienthh\n");
    max_noeudleght = ft_Get_MaxNoueud_Length(*a);
    // printf("ft_Get_MaxNoueud_Length(*a) = %d\n",max_noeudleght->valeur);
    // afficher_sub_ptr(*a);;
    // exit(0);
    while (max_noeudleght)
    {
        max_noeudleght->appartient = true;
        max_noeudleght = max_noeudleght->sub_ptr;
    }
        // printf("mohcine afichage\n");
}

void ft_lis(t_noeud **a)
{
    t_noeud     *i;
    t_noeud     *j;

    j = *a;
    i = *a;
    while (i)
    {
        j = i->suivant;
        while (j)
        {
            if (i->valeur < j->valeur && i->length + 1 >= j->length)
            {
                j->length = i->length + 1;
                j->sub = i->indice;
                j->sub_ptr = i;
            }
            j = j->suivant;
        }
        i = i->suivant;
    }
    // printf("dans ft_lis\n");
    // afficher_sub_ptr(*a);
    // exit(0);
    ft_appartient(a);
}