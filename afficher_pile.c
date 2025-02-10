#include "push_swap.h"

void afficher_pile(t_noeud *pile)
{
    t_noeud *tmp;

    if (!pile)
    {
        printf("Pileest vide.\n");
        return;
    }
    printf("pile->");
    tmp = pile;
    while (tmp)
    {
        printf("%d", tmp->valeur);
        if (tmp->suivant)
            printf("->");
        tmp = tmp->suivant;
    }
    printf("\n");
}
void afficher_sub_ptr(t_noeud *pile)
{
    t_noeud *tmp;

    if (!pile)
    {
        printf("Pileest vide.\n");
        return;
    }
    printf("pile: \n");
    tmp = pile;
    printf("->");
    while (tmp)
    {
        printf("adreese =%p\tvaleur = %d\tlength = %d\tsub = %d\t\tindice = %d\tappartien = %d\tsub_ptr = %p\n", tmp,tmp->valeur,tmp->length,tmp->sub,tmp->indice,tmp->appartient,tmp->sub_ptr);
        if (tmp->suivant)
            printf("->");
        tmp = tmp->suivant;
    }
    printf("fin pile: \n");
}

// void afficher_sub_ptr(t_noeud *pile)
// {
//     t_noeud *tmp;

//     if (!pile)
//     {
//         printf("Pileest vide.\n");
//         return;
//     }
//     printf("pile->");
//     tmp = pile;
//     while (tmp)
//     {
//         if (tmp->appartient)
//             printf("%d", tmp->valeur);
//         if (tmp->suivant)
//             printf("->");
//         tmp = tmp->suivant;
//     }
//     printf("\n");
// }
