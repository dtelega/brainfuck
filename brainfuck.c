/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:13:52 by dtelega           #+#    #+#             */
/*   Updated: 2016/12/26 17:26:33 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	plus_minus(char arr, char znak)
{
	if (znak == '+')
		return (arr + 1);
	else
		return (arr - 1);
}

int		more_less(int i, char znak)
{
	if (znak == '>')
		return (i + 1);
	else
		return (i - 1);
}

int		skoba(int x, char znak, char *av, int sk)
{
	if (znak == '[')
		while (sk != 0)
		{
			x++;
			if (av[x] == '[')
				sk++;
			else if (av[x] == ']')
				sk--;
		}
	if (znak == ']')
		while (sk != 0)
		{
			x--;
			if (av[x] == ']')
				sk++;
			else if (av[x] == '[')
				sk--;
		}
	return (x);
}

int		main(int ac, char **av)
{
	char	s[4096];
	int		i;
	int		x;

	if (ac == 2 && (i = 0) == 0)
	{
		while (i < 4096 && (x = -1))
			s[i++] = '\0';
		i = 0;
		while (av[1][++x])
		{
			if (av[1][x] == '+' || av[1][x] == '-')
				s[i] = plus_minus(s[i], av[1][x]);
			else if (av[1][x] == '>' || av[1][x] == '<')
				i = more_less(i, av[1][x]);
			else if (av[1][x] == '.')
				write(1, &s[i], 1);
			else if ((av[1][x] == '[' && !s[i]) || (av[1][x] == ']' && s[i]))
				x = skoba(x, av[1][x], av[1], 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
