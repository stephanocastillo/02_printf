/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:49:44 by axcastil          #+#    #+#             */
/*   Updated: 2023/11/23 21:30:00 by axcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int n, size_t *number)
{
	long int	i;

	i = n;
	if (n == -2147483648)
	{
		ft_putstr_printf("-2147483648", number);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_printf('-', number);
	}
	if (n > 9)
	{
		ft_putnbr_printf((n / 10), number);
		ft_putchar_printf(((n % 10) + 48), number);
	}
	else
		ft_putchar_printf((n + 48), number);
}

/*void	ft_putaddress_printf(unsigned long long *address, size_t *number)
{
	char	*address2;
	
		
}*/

void	ft_puthexadown_printf(unsigned long long n, size_t *number)
{
	char	storage[16];
	int		i;
	
	i = 0;
	if (n == 0)
	{
		ft_putchar_printf('0', number);
		return;
	}
	while(n > 0)
	{
		if ((n % 16) > 9)
			storage[i] = (n % 16) + 87; 
		else if ((n % 16) < 10)
			storage[i] = (n % 16) + 48;
		n /= 16;
		i ++;
	}
	while(i--)
		ft_putchar_printf(storage[i], number);
}

void	ft_puthexaup_printf(unsigned long long n, size_t *number)
{
	char	storage[16];
	int		i;
	
	i = 0;
	if (n == 0)
	{
		ft_putchar_printf('0', number);
		return;
	}
	while(n > 0)
	{
		if ((n % 16) > 9)
			storage[i] = (n % 16) + 55; 
		else if ((n % 16) < 10)
			storage[i] = (n % 16) + 48;
		n /= 16;
		i ++;
	}
	while(i--)
		ft_putchar_printf(storage[i], number);

}

int main()
{
	unsigned long long	a = 987654;
	size_t i = 0;
	ft_putnbr_printf(a, &i);
	return 0;
}
