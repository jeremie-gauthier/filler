/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:37:48 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:39:18 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, const char *banned,
						size_t *len);
char				*ft_strcapitalize(char *s);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *s);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
char				*ft_strcasestr(const char *s1, const char *s2);
char				*ft_strndup(const char *s, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_printtab(char **tab);
void				ft_strrev(char *s);
int					brackets(char *str);
void				ft_tabdel(void **tab, size_t size);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strpbrk(const char *s, const char *accept);
int					ft_instr(const char c, const char *accept);
char				*ft_strncpy_safe(char *dest, const char *src, size_t n);
size_t				ft_arrlen(void **arr);
size_t				ft_strlen(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strspn(const char *s, const char *accept);
void				ft_bzero(void *s, size_t n);
char				*ft_strcdup(const char *str, const char *limits);
char				*ft_arrjoin(const char **arr, const int glue);
char				*replace_substr(const char *str, const char *substr,
						const char *replacement);
char				*glue_str(char const *s1, char const *s2, char glue);

#endif
