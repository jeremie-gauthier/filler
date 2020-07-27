/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:57:25 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/27 11:33:25 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <sys/types.h>
# include <unistd.h>

typedef struct		s_file
{
	struct s_file	*next;
	char			*str;
	int				fd;
}					t_file;

int					get_next_line(const int fd, char **line);
void				bufferize(const char *src, const size_t len);
void				print_buffer(void);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				putnbr_base(int n, int base);

#endif
