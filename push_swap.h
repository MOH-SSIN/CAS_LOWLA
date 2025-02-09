/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:30:09 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/09 17:01:20 by mez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H



#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "unistd.h"
#include "stdbool.h"


typedef struct s_noeud
{
    int             valeur;         
    int             indice;
    int             length;
    int             sub;
    int             push_price;
    bool            appartient;
    bool            au_dessus_median;
    bool            moins_cher;
    struct s_noeud     *sub_ptr;
    struct s_noeud *noeud_cible;
    struct s_noeud *suivant; 
    struct s_noeud *precedent;
} t_noeud;


int ft_vide_space(char *str);

//concat_arg
char	**concat_arg(int ac, char *av[]);

// fonction cheker_erreur
void liberer_erreurs(char **split);
int ft_vide_space(char *str);
void Parse_ArgEnd_Init_a(t_noeud **a, t_noeud **b, char **args);


// libft
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int     ft_isdigit(int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

// creat pile
t_noeud *lstnew(char *args, int indice);
t_noeud *lslast(t_noeud *last);
void lsadd_back(t_noeud **pile, t_noeud *new);
t_noeud *ajouter_noeud(char **args);

//aficher
void afficher_pile(t_noeud *pile);
void afficher_sub_ptr(t_noeud *pile);
//push_swap_utils.c
int pile_taile(t_noeud *a);
int pile_trie(t_noeud *a);


//free.c
void	fr_single(char **s1, char **s2);
void liberer_erreurs(char **split);
void free_pile(t_noeud *pile);
void free_piles(t_noeud *a, t_noeud *b);

//ptit_piles.c
void case_ptit_piles(t_noeud **a, t_noeud **b);

//case_grand_pile.c
void case_grand_pile(t_noeud **a, t_noeud **b);

// lis
void ft_lis(t_noeud **a);

//case_grand_pile.c 
void push_non_list(t_noeud **a, t_noeud**b);


//init_pile.c
void    set_moins_cher(t_noeud *pile);
void init_pile(t_noeud **a, t_noeud **b);




// LES OPERATIONS
// void swap(t_noeud **pile);
void sa(t_noeud **a , bool afch);
void sb(t_noeud **b , bool afch);
void ss(t_noeud **a, t_noeud **b, bool afch);

// void rotate(t_noeud **pile);
void ra(t_noeud **a, bool afch);
void rb(t_noeud **b, bool afch);
void rr(t_noeud **a, t_noeud **b, bool afch);

// void reverse_rotate(t_noeud **pile);
void rra(t_noeud **a, bool afch);
void rrb(t_noeud **b, bool afch);
void rrr(t_noeud **a, t_noeud **b, bool afch);

void pa(t_noeud **a, t_noeud **b, bool afch);
void pb(t_noeud **a, t_noeud **b, bool afch);
#endif
