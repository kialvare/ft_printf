/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 08:34:46 by kialvare          #+#    #+#             */
/*   Updated: 2017/01/19 08:34:48 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_arrlen(void **arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}
