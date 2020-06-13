/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:01:29 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 13:13:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_DEFINES_H
# define LFT_DEFINES_H

# define OUTBUF		4096

# define BUFF_SIZE	256
# define IDENTICAL	0
# define ALL_FLAGS	"Llh+- .#0123456789,*"
# define NB_FLAGS	20
# define ALL_CONV	"cspdiouxXbf%"
# define NB_CONV	12
# define REDIRECT	"DIOU"
# define NB_REDIRECT	4
# define INT_CONV	"di"
# define UINT_CONV	"ouxXb"
# define NUMERIC_CONV	"diouxXb"
# define NB_NUM_CONV	7
# define BASE_CONV	"oxXb"
# define CHAR_CONV	"cs%"
# define SEPARABLES	"iduf"

/*
**	COLORS
*/

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define REVERSE	"\033[7m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define BG_BLACK	"\033[40m"
# define BG_RED		"\033[41m"
# define BG_GREEN	"\033[42m"
# define BG_YELLOW	"\033[43m"
# define BG_BLUE	"\033[44m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"
# define CLEAR		"\e[1;1H\e[2J"

#endif
