/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:55:52 by iusantos          #+#    #+#             */
/*   Updated: 2023/11/13 13:39:55 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_inode
{
	int				number;
	struct s_inode	*next;
	struct s_inode	*prev;
}	t_inode;


int	is_int(char *str); //returns 0 if str is not an integer (disregards range)
#endif //PUSH_SWAP_H
