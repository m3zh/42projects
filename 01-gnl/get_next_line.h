/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebodart <ebodart@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:32:35 by ebodart           #+#    #+#             */
/*   Updated: 2021/03/01 14:36:57 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_find_newline(const char *s, int c);
int		ft_fill_line(char **keep, char **line, int fd);
int		ft_free_and_return(char **keep, int ret);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_update_static(char **keep, char *buf, int fd);
void	ft_free(char **line);
size_t	ft_strlen(const char *str);

#endif
