# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/13 20:07:20 by jergauth          #+#    #+#              #
#    Updated: 2020/06/20 17:24:41 by jergauth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	jergauth.filler

OBJS_DIRNAME= .objs

## COMMON SOURCES
SRCS_DIR= ./srcs
SRCS=	mem_clear.c\
			mem_init.c\
			heatmap.c\
			main.c\
			read_map.c\
			read_piece.c\
			play_piece.c

## COMMON OBJS
OBJS= $(SRCS:.c=.o)
OBJS_DIR= $(SRCS_DIR)/$(OBJS_DIRNAME)
OBJS_PRE= $(addprefix $(OBJS_DIR)/, $(OBJS))

ALL_DIR= $(OBJS_DIR)
ALL_PRE= $(OBJS_PRE)

## LIB
LIBFT_DIR= ./libft

## HEADERS
HEADER_DIR=	includes/
HEADER=	filler.h

HEADERS= $(addprefix $(HEADER_DIR), $(HEADER))

## INCLUDES
INC= -I ./$(HEADER_DIR)
LIB_INC= -I $(addprefix $(LIBFT_DIR)/, $(HEADER_DIR))
INCS = $(INC) $(LIB_INC)

CC		=	clang
CFLAGS	+= -Wall -Werror -Wextra

LFLAGS	+= -L $(LIBFT_DIR) -lft

## DEBUG SYMBOLS
DSYM= $(NAME).dSYM

## RULES
all:	LIBFT $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

$(NAME):	$(ALL_DIR) $(ALL_PRE) $(HEADERS) $(LIBFT_DIR) Makefile
			$(CC) -o $(NAME) $(CFLAGS) $(ALL_PRE) $(LFLAGS)

LIBFT:
		@make -C $(LIBFT_DIR)

clean:	
		rm -rf $(ALL_DIR) $(DSYM)
		@make -C $(LIBFT_DIR) clean

fclean:	clean
		rm -rf $(NAME)
		@make -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re LIBFT
