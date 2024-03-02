/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 06:57:10 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/02 06:57:13 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
    int file_descriptor = open("1.txt", O_RDONLY);
    char* line = get_next_line(file_descriptor);
    line = get_next_line(file_descriptor);
     printf("%s",line);
    line = get_next_line(file_descriptor);

    // Process the line

    // Free the memory allocated for the line
    printf("%s",line);
    free(line);
    close(file_descriptor);
    return (0);
}
