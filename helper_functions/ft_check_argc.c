/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:30:42 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/09 02:46:20 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

static int	ft_check_duplication(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	check_digits(char **args, int i)
{
	const char	*max_int_str1;
	const char	*max_int_str2;
	const char	*min_int_str;

	max_int_str1 = "+2147483647";
	max_int_str2 = "2147483647";
	min_int_str = "-2147483648";
	if (args[i][0] == '-')
	{
		if (ft_strlen(args[i]) > 11 || ft_strcmp(args[i], min_int_str) > 0)
			return (1);
	}
	else if (args[i][0] == '+')
	{
		if (ft_strlen(args[i]) > 11 || (ft_strlen(args[i]) == 11
				&& ft_strcmp(args[i], max_int_str1) > 0))
			return (1);
	}
	else
	{
		if (ft_strlen(args[i]) > 10 || (ft_strlen(args[i]) == 10
				&& ft_strcmp(args[i], max_int_str2) > 0))
			return (1);
	}
	return (0);
}

static int	ft_help_check_argc(long tmp, char **args, int i)
{
	if (!ft_isnum(args[i]))
		return (-1);
	if (ft_check_duplication(tmp, args, i))
		return (-1);
	if (check_digits(args, i))
		return (-1);
	return (0);
}


int	ft_check_argc(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc < 2)
		return (-1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (ft_help_check_argc(tmp, args, i) == -1)
			return (-1);
		i++;
	}
	if (argc == 2)
		free_split(args);
	return (0);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	if (ft_check_argc(argc, argv) == -1)
// 		printf("error");
// 	else
// 		printf("success");
// 	return (0);
// }
