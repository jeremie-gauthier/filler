/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:01:59 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:40:57 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_valid(char *str)
{
	int		par;
	int		cro;
	int		acc;

	par = 0;
	cro = 0;
	acc = 0;
	while (*str)
	{
		if (*str == '(')
			par++;
		else if (*str == '[')
			cro++;
		else if (*str == '{')
			acc++;
		else if (*str == ')')
			par--;
		else if (*str == ']')
			cro--;
		else if (*str == '}')
			acc--;
		str++;
	}
	return ((acc | par | cro) == 0);
}

static int	parse(char **str, char c)
{
	char	inverse;

	inverse = (c == 40) ? c + 1 : c + 2;
	(*str)++;
	while (**str && **str != ']' && **str != ')' && **str != '}')
	{
		if (**str == '(' || **str == '[' || **str == '{')
		{
			if (parse(str, **str) == 0)
				return (0);
		}
		(*str)++;
	}
	if (**str == inverse)
		return (1);
	return (0);
}

int			brackets(char *str)
{
	if (check_valid(str) == 0)
		return (0);
	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
		{
			if (parse(&str, *str) == 0)
				return (0);
		}
		str++;
	}
	return (1);
}
