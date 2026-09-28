/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdinput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:01:50 by soyamagu          #+#    #+#             */
/*   Updated: 2025/12/29 20:03:26 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*result;
	
	while (1)
	{
		result = get_next_line(STDIN_FILENO);
		if (!result)
			break ;
		printf("%s", result);
		free (result);
	}
	return (0);
}