/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:11:59 by itahri            #+#    #+#             */
/*   Updated: 2024/05/25 22:21:55 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += monitoring(args, (char *)&format[i]);
			format += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (i + count);
}
/*
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf("ft : \n");
	printf("%d\n", ft_printf(NULL));
	printf("original : \n");
	printf("%d\n", printf(NULL));
}
*/
