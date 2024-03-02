/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 07:58:56 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/02 07:58:57 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t s1, size_t s2);
char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next_line(char *buffer);
char	*ft_drop_and_join(char *buffer, char *buf);
#endif
