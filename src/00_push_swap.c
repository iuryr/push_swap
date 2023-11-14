/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:41 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/14 15:10:25 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//returns 1 if str is a "proper" int, disregarding range. 0 otherwise
int	is_int(char *str)
{
	if (!*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		else
			str++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		exit(1);
	i = 1;
	while(i < argc)
	{
		ft_printf("%s argv[%d]: %d\n", argv[i], i, is_int(argv[i]));
		i++;
	}
}
