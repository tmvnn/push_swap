/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <lbellona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:14:06 by lbellona          #+#    #+#             */
/*   Updated: 2019/09/15 22:50:58 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			valid_and_sort(t_push_swap *ps)
{
	char	*line;

	line = 0;
	ps->size_a = ps->size;
	ps->size_b = 0;
	ps->stack_b = 0;
	print_stacks(ps);
	while (get_next_line(0, &line) > 0 && *line != 0)
	{
		check_and_do_op(line, ps);
		print_stacks(ps);
	}
	free(line);
}

int				main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		if (fill_stack(&ps.stack_a, argv) &&
										(ps.size = no_duplicates(ps.stack_a)))
		{
			valid_and_sort(&ps);
			if (check_sort(ps.stack_a) && !stack_is_empty(ps.stack_b))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			return ((int)pr_error());
	}
	return (0);
}
