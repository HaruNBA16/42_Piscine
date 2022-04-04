/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haksu <haksu@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 07:15:11 by haksu             #+#    #+#             */
/*   Updated: 2022/04/04 07:15:25 by haksu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putvet(int vet[], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		putchar(vet[i] + '0');
		i++;
	}
}

int		get_index(int combn[], int n)
{
	int i;
	int max;

	i = 0;
	max = 10 - n;
	while (i < n)
	{
		if (combn[i] == max)
			return (i - 1);
		if (i == (n - 1) && combn[i] < max)
			return (i);
		i++;
		max++;
	}
	return (-1);
}

void	increment(int vet[], int n, int index)
{
	int i;

	i = index + 1;
	vet[index]++;
	while (i <= n)
	{
		vet[i] = vet[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int combn[n];
	int i;
	int pos_index;

	if (n >= 10 || n <= 0)
		return ;
	else
	{
		i = 0;
		while (i < n)
		{
			combn[i] = i;
			i++;
		}
		while (get_index(combn, n) != -1) 
		{
			pos_index = get_index(combn, n); 
			putvet(combn, n); 
			increment(combn, n, pos_index);
			write(1, ", ", 2);
		}
		putvet(combn, n); 
	}
}

int main(void)
{
	ft_print_combn(2);
	return (0);
}