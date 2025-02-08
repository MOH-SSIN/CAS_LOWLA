/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:30:09 by mez-zahi          #+#    #+#             */
/*   Updated: 2025/02/08 16:56:14 by mez-zahi         ###   ########.fr       */
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
#endif