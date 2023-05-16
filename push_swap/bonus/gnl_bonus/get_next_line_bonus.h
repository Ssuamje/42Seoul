/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:33:28 by sanan             #+#    #+#             */
/*   Updated: 2023/01/04 23:27:57 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif
# include <unistd.h>
# include <stdlib.h>

void	ft_strlcpy_2(char *dest, char *src, size_t size);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strjoin_free(char *s1, char *s2, size_t len_s2);
ssize_t	get_idx_nl(char *string, size_t len);
char	*free_str(char **s1, char **s2);
char	*init_str(size_t size);
char	*read_paste_till_last(int fd, char **buf, char **output, ssize_t *rd);
char	*parse_last(char **left, char **buf, char **output, ssize_t *rd);
char	*set_output_left(char **left, char **buf, ssize_t *rd, int fd);
char	*get_next_line(int fd);

#endif
