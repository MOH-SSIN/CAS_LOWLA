#include "push_swap.h"


static t_noeud *ft_get_moins_cher(t_noeud *pile)
{
    if (NULL == pile)
		return (NULL);
	while (pile)
	{
		if (pile->moins_cher)
			return (pile);
		pile = pile->suivant;
	}
	return (NULL);
}


static void	rotate_both(t_noeud **a,
						t_noeud **b,
						t_noeud *cheapest_node)
{
	while (*a != cheapest_node->noeud_cible
		&& *b != cheapest_node)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

static void	reverse_rotate_both(t_noeud **a,
								t_noeud **b,
								t_noeud *cheapest_node)
{
	while (*a != cheapest_node->noeud_cible
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}


static void	finish_rotation(t_noeud **stack,
							t_noeud *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->moins_cher)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->moins_cher)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

void move_b_vers_a(t_noeud **a, t_noeud **b)
{
    t_noeud *moins_cher;

    moins_cher = ft_get_moins_cher(*b);
    if (moins_cher->au_dessus_median && moins_cher->noeud_cible->au_dessus_median)
        rotate_both(a, b, moins_cher);
    else if (!(moins_cher->au_dessus_median) && !(moins_cher->noeud_cible->au_dessus_median))
        reverse_rotate_both(a, b, moins_cher);
    finish_rotation(b, moins_cher, 'b');
    finish_rotation(a, moins_cher->noeud_cible, 'a');
    pa(a, b, false);
}


