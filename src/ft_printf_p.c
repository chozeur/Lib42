/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:45:02 by flcarval          #+#    #+#             */
/*   Updated: 2022/04/01 01:04:18 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(void *ptr)
{
	unsigned long int	ad;

	if (!ptr)
		return (ft_putstr("0x0"));
	ad = (unsigned long int)ptr;
	ft_putstr("0x");
	return (ft_putulhex(ad) + 2);
}
