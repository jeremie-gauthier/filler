/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:29:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:29:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
long				ft_atol_base(const char *str, int base);
char				*ft_ltoa_base(long nb, short base);
char				*ft_ultoa_base(unsigned long nb, short base);
char				*ft_lltoa_base(long long nb, short base);
char				*ft_ulltoa_base(unsigned long long nb, short base);
char				*ft_itoa_base(int nb, int base);
char				*ft_uitoa_base(unsigned int nb, int base);
char				*ft_itoa(int n);

#endif
