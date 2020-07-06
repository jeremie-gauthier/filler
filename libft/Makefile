NAME	=	libft.a
UNAME	:= $(shell uname)

OBJS_DIRNAME= .objs

TREES_DIR=	avl_trees
TREES_SRCS=	btree_apply_prefix.c\
			btree_apply_infix.c\
			btree_apply_postfix.c\
			btree_balancing.c\
			btree_create_node.c\
			btree_del.c\
			btree_insert_data.c\
			btree_remove_node.c\
			btree_search_data.c

TREES_OBJS= $(TREES_SRCS:.c=.o)
TREES_OBJS_DIR= $(TREES_DIR)/$(OBJS_DIRNAME)
TREES_OBJS_PRE= $(addprefix $(TREES_OBJS_DIR)/, $(TREES_OBJS))

COMP_DIR= comparisons
COMP_SRCS=	ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_isoperator.c\
			ft_isblank.c\
			ft_iscntrl.c\
			ft_isgraph.c\
			ft_islower.c\
			ft_isspace.c\
			ft_isupper.c\
			ft_isxdigit.c\
			ft_str_is_alpha.c\
			ft_str_is_lowercase.c\
			ft_str_is_numeric.c\
			ft_str_is_printable.c\
			ft_str_is_alnum.c\
			ft_str_is_uppercase.c

COMP_OBJS= $(COMP_SRCS:.c=.o)
COMP_OBJS_DIR= $(COMP_DIR)/$(OBJS_DIRNAME)
COMP_OBJS_PRE= $(addprefix $(COMP_OBJS_DIR)/, $(COMP_OBJS))

CONV_DIR= conversions
CONV_SRCS=	ft_atoi.c\
			ft_atoi_base.c\
			ft_atol_base.c\
			ft_itoa.c\
			ft_itoa_base.c\
			ft_ltoa_base.c\
			ft_lltoa_base.c\
			ft_ultoa_base.c\
			ft_ulltoa_base.c\
			ft_uitoa_base.c

CONV_OBJS= $(CONV_SRCS:.c=.o)
CONV_OBJS_DIR= $(CONV_DIR)/$(OBJS_DIRNAME)
CONV_OBJS_PRE= $(addprefix $(CONV_OBJS_DIR)/, $(CONV_OBJS))

PRINTF_DIR= ft_printf
PRINTF_SRCS=	conv_double.c\
				conv_numeric.c\
				conv_ptr.c\
				conv_str.c\
				format_char.c\
				format_comma.c\
				format_flags.c\
				format_numeric.c\
				format_precision.c\
				format_regular_op.c\
				ft_dtoa.c\
				ft_ldtoa.c\
				ft_dtoa_concat.c\
				ft_printf.c\
				ft_vprintf.c\
				ft_putdouble.c\
				putlnbr_base.c\
				memory.c\
				parse_color.c\
				parse_flag.c\
				parse_format.c\
				select_conversion.c

PRINTF_OBJS= $(PRINTF_SRCS:.c=.o)
PRINTF_OBJS_DIR= $(PRINTF_DIR)/$(OBJS_DIRNAME)
PRINTF_OBJS_PRE= $(addprefix $(PRINTF_OBJS_DIR)/, $(PRINTF_OBJS))

IO_DIR=	IO
IO_SRCS=	buffer.c\
			ft_printtab.c\
			get_next_line.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_putnbr.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			putnbr_base.c

IO_OBJS= $(IO_SRCS:.c=.o)
IO_OBJS_DIR= $(IO_DIR)/$(OBJS_DIRNAME)
IO_OBJS_PRE= $(addprefix $(IO_OBJS_DIR)/, $(IO_OBJS))

LST_DIR= linked_lists
LST_SRCS=	cycle_detector.c\
			ft_lstnew.c\
			ft_lstnew_addr.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstadd_back.c\
			ft_lstpop.c

LST_OBJS= $(LST_SRCS:.c=.o)
LST_OBJS_DIR= $(LST_DIR)/$(OBJS_DIRNAME)
LST_OBJS_PRE= $(addprefix $(LST_OBJS_DIR)/, $(LST_OBJS))

MATH_DIR= math
MATH_SRCS=	ft_abs.c\
			ft_pow_ten.c\
			ft_range.c\
			ft_swap.c

MATH_OBJS= $(MATH_SRCS:.c=.o)
MATH_OBJS_DIR= $(MATH_DIR)/$(OBJS_DIRNAME)
MATH_OBJS_PRE= $(addprefix $(MATH_OBJS_DIR)/, $(MATH_OBJS))

MEM_DIR= mem
MEM_SRCS=	ft_memset.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_memjoin.c\
			ft_memjoin_free.c

MEM_OBJS= $(MEM_SRCS:.c=.o)
MEM_OBJS_DIR= $(MEM_DIR)/$(OBJS_DIRNAME)
MEM_OBJS_PRE= $(addprefix $(MEM_OBJS_DIR)/, $(MEM_OBJS))

STR_DIR= str
STR_SRCS=	brackets.c\
			replace_substr.c\
			glue_str.c\
			ft_bzero.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_strcpy.c\
			ft_strncpy.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strspn.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strclr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_strsplit.c\
			ft_strcapitalize.c\
			ft_strlowcase.c\
			ft_strupcase.c\
			ft_strcasecmp.c\
			ft_strncasecmp.c\
			ft_strcasestr.c\
			ft_strndup.c\
			ft_strcdup.c\
			ft_strrev.c\
			ft_strlcpy.c\
			ft_tabdel.c\
			ft_strjoin_free.c\
			ft_strpbrk.c\
			ft_instr.c\
			ft_strncpy_safe.c\
			ft_arrlen.c\
			ft_arrjoin.c

STR_OBJS= $(STR_SRCS:.c=.o)
STR_OBJS_DIR= $(STR_DIR)/$(OBJS_DIRNAME)
STR_OBJS_PRE= $(addprefix $(STR_OBJS_DIR)/, $(STR_OBJS))

ALL_DIR= $(TREES_OBJS_DIR) $(COMP_OBJS_DIR) $(CONV_OBJS_DIR) $(PRINTF_OBJS_DIR) $(IO_OBJS_DIR) $(LST_OBJS_DIR) $(MATH_OBJS_DIR) $(MEM_OBJS_DIR) $(STR_OBJS_DIR)
ALL_PRE= $(TREES_OBJS_PRE) $(COMP_OBJS_PRE) $(CONV_OBJS_PRE) $(PRINTF_OBJS_PRE) $(IO_OBJS_PRE) $(LST_OBJS_PRE) $(MATH_OBJS_PRE) $(MEM_OBJS_PRE) $(STR_OBJS_PRE)

ifeq ($(UNAME), Darwin)
CC		=	gcc
CFLAGS	+=	-Wall -Werror -Wextra
endif

ifeq ($(UNAME), Linux)
CC		=	clang
CFLAGS	+=	-Wall -Werror -Wextra
endif

## HEADERS
HEADER_DIR=	includes/
HEADER=	libft.h\
		ft_printf.h\
		avl_trees.h\
		comparisons.h\
		conversions.h\
		lft_defines.h\
		io.h\
		linked_lists.h\
		math.h\
		mem.h\
		str.h

HEADERS= $(addprefix $(HEADER_DIR), $(HEADER))

## INCLUDES
INCS= -I ./$(HEADER_DIR)

RM		=	rm -rf

CLEAN	=	clean

all:		$(NAME)

$(TREES_OBJS_DIR)/%.o: $(TREES_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(TREES_OBJS_DIR):
			@mkdir -p $(TREES_OBJS_DIR)

$(COMP_OBJS_DIR)/%.o: $(COMP_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(COMP_OBJS_DIR):
			@mkdir -p $(COMP_OBJS_DIR)

$(CONV_OBJS_DIR)/%.o: $(CONV_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(CONV_OBJS_DIR):
			@mkdir -p $(CONV_OBJS_DIR)

$(PRINTF_OBJS_DIR)/%.o: $(PRINTF_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(PRINTF_OBJS_DIR):
			@mkdir -p $(PRINTF_OBJS_DIR)

$(IO_OBJS_DIR)/%.o: $(IO_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(IO_OBJS_DIR):
			@mkdir -p $(IO_OBJS_DIR)

$(LST_OBJS_DIR)/%.o: $(LST_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(LST_OBJS_DIR):
			@mkdir -p $(LST_OBJS_DIR)

$(MATH_OBJS_DIR)/%.o: $(MATH_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(MATH_OBJS_DIR):
			@mkdir -p $(MATH_OBJS_DIR)

$(MEM_OBJS_DIR)/%.o: $(MEM_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(MEM_OBJS_DIR):
			@mkdir -p $(MEM_OBJS_DIR)

$(STR_OBJS_DIR)/%.o: $(STR_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(STR_OBJS_DIR):
			@mkdir -p $(STR_OBJS_DIR)

$(NAME):	$(ALL_DIR) $(ALL_PRE) $(HEADERS) Makefile
			ar rc $(NAME) $(ALL_PRE)
			ranlib $(NAME)

$(OBJS_DIRNAME)/%.o: %.c
			@mkdir -p $(OBJS_DIRNAME)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

clean:	
			@$(RM) $(ALL_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
