/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:10:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/07 17:10:55 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sorted_final_stack(t_stack *a)
{
	int	i;
	int	mod;

	if (a)
	{
		i = 0;
		mod = a->index_max + 1;
		while (++i <= mod && a->next && (a->index + 1)%mod == a->next->index)
			a = a->next;
		if (i == mod && !(a->next))
			return (1);
	}
	return (0);
}

void	set_sorted_final_stack_ontop(t_stack **a)
{
	if (*a && sorted_final_stack(*a))
		extract_target_ontop(0, a);
}

int	sorted_final_stack_ontop(t_stack *a)
{
	return (a && sorted_final_stack(a) && !(top_stack(a)->index));
}

static	void	moves_tb_direct_neighbors(t_stack **a)
{
	if (top_bottom_in_order(*a))
		rotate_a(a);
	else
	{
		reverserotate_a(a);
		swap_a(a);
	}
}

static	void	moves_ts_direct_neighbors(t_stack **a)
{
	if (top_second_in_order(*a))
		ra_twice_if_necessary(a);
	else
		swap_a(a);
}

void	algo_four(t_stack **a)
{
	if (*a)
	{
		while (!sorted_final_stack(*a))
		{
			if (top_second_dneighbors(*a))
				moves_ts_direct_neighbors(a);
			else if (top_bottom_dneighbors(*a))
				moves_tb_direct_neighbors(a);
			else
				rotate_a(a);
		}
		set_sorted_final_stack_ontop(a);
	}
}
