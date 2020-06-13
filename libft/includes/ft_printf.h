/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:24:54 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:26:32 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdarg.h>

typedef struct		s_buf
{
	void			*str;
	size_t			len;
}					t_buf;

typedef struct		s_flags
{
	int				prc;
	int				pad;
	char			c;
	unsigned short	hh	: 1;
	unsigned short	h	: 1;
	unsigned short	l	: 1;
	unsigned short	ll	: 1;
	unsigned short	lm	: 1;
	unsigned short	dz	: 1;
	unsigned short	f0	: 1;
	unsigned short	mo	: 1;
	unsigned short	pl	: 1;
	unsigned short	sp	: 1;
	unsigned short	com	: 1;
	unsigned short	base: 5;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_sprintf(char *str, const char *format, ...);
int					ft_snprintf(char *s, size_t size, const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_vsprintf(char *s, const char *format, va_list ap);
int					ft_vsnprintf(char *s, size_t size, const char *format,
						va_list ap);
int					ft_vdprintf(int fd, const char *format, va_list ap);
t_buf				*init_buf(void);
t_flags				*init_flags(void);
void				add_flag(const char c, t_flags *fl);
int					parse_format(const char **format, t_buf *buf);
int					parse_flags(const char **format, t_buf *buf, va_list ap);
int					ft_parse_color(const char **format, t_buf *buf);
void				redirection_conversion(t_flags *fl);
int					conversion(t_flags *fl, t_buf *buf, va_list ap);
int					ft_conv_numeric(t_flags *fl, t_buf *buf, va_list ap);
int					ft_conv_double(t_flags *fl, t_buf *buf, va_list ap);
int					ft_conv_str(t_flags *fl, t_buf *buf, va_list ap);
int					ft_conv_ptr(t_flags *fl, t_buf *buf, va_list ap);
int					ft_format_flag(t_flags *fl, char **conv);
int					ft_format_prc(t_flags *fl, char **conv, int *len);
int					ft_zero_value_numeric_conv_zero_prc(t_flags *fl,
						char **conv);
int					ft_format_plus_space(t_flags *fl, char **conv, int sign);
int					compute_padding_len(t_flags *fl, int len, int sign);
int					ft_format_padding(t_flags *fl, char **conv, int len,
						int sign);
int					ft_format_diese(t_flags *fl, char **conv);
int					ft_format_char(t_flags *fl, t_buf *buf, unsigned char c);
int					ft_format_str(t_flags *fl, char **conv, int len,
						t_buf *buf);
int					dieze_position(t_flags *fl, char **conv, int len, int sign);
int					plus_position(t_flags *fl, char **conv, int len, int sign);
int					format_sign(t_flags *fl, char **conv, int len, int sign);
int					format_no_sign(t_flags *fl, char **conv, int len, int sign);
int					ft_format_comma(t_flags *fl, char **conv);
void				ft_putdouble(double d, unsigned short precision);
void				putlnbr_base(long n, short base);
char				*ft_dtoa(double d, unsigned short precision);
char				*ft_ldtoa(long double d, unsigned short precision);
char				*ft_dtoa_concat(char *s, long l, int sign);
char				*ft_ldtoa_concat(char *s, long long l, int sign);

#endif
