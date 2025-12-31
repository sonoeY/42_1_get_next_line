/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_txtfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:42 by soyamagu          #+#    #+#             */
/*   Updated: 2025/12/29 20:05:18 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*result;
	int		fd;

	if (argc != 2)
	{
		printf("error\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		result = get_next_line(fd);
		if (!result)
			break ;
		printf("%s", result);
		free (result);
	}
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	//printf("%zu", SIZE_MAX); //18446744073709551615
	close (fd);
	return (0);
}
