#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 12:50:44 by lpousse           #+#    #+#              #
#    Updated: 2017/03/06 11:00:10 by nhuber           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CONV_NAME = ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c ft_ltoa.c ft_lltoa.c ft_htoa.c ft_hhtoa.c ft_utoa.c ft_lutoa.c ft_llutoa.c ft_hutoa.c ft_hhutoa.c ft_stoa_base.c ft_utoa_base.c ft_atod.c ft_atoi_fwd.c ft_strupcase.c
FILE_NAME = ft_gnl.c
FT_PRINTF = ft_printf.c char_converters.c str_converters.c int_converter.c uint_converters.c pointer_converter.c parsing.c ft_dprintf.c ft_asprintf.c
IS_NAME = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isupper.c ft_isoneof.c ft_isspace.c ft_isincluded.c
LST_NAME = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
MAT_NAME = ft_matnew.c ft_matset.c ft_matclr.c ft_matdel.c ft_matadd.c ft_matmulti.c ft_mattransp.c ft_matmulti_scal.c ft_matsub.c ft_matdet.c ft_matsetsub.c ft_matinvert.c ft_vectnew.c ft_vectset.c ft_vectclr.c ft_vectdel.c ft_vectadd.c ft_vectsub.c ft_vectmulti.c ft_vectmulti_scal.c ft_vectscal.c ft_matvectmulti.c ft_matmultidel.c ft_matidentity.c
MEM_NAME = ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_ptrswap.c
NBR_NAME = ft_intlen.c ft_intlen_base.c ft_intmaxlen_base.c ft_uintmaxlen_base.c ft_swap.c ft_max.c ft_min.c ft_abs.c ft_uswap.c ft_pow.c ft_umax.c ft_umin.c
PUT_NAME = ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putnbr_base.c ft_puts_base.c ft_putu_base.c ft_puts_base_caps.c ft_putu_base_caps.c ft_putwchar.c ft_putwstr.c ft_putintmax.c ft_putintmaxns.c ft_putnstr.c ft_putnwstr.c ft_putsizewstr.c ft_putmat.c ft_putlong.c ft_putdouble.c ft_putwchar_fd.c ft_putwstr_fd.c ft_putnstr_fd.c ft_putnwstr_fd.c ft_putsizewstr_fd.c ft_putintmaxns_fd.c ft_putu_base_fd.c ft_putu_base_caps_fd.c ft_putnstr_noend.c ft_putnstr_noend_fd.c
STR_NAME = ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnjoin.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_strfillwith.c ft_nbword.c ft_strswap.c ft_sortalpha.c ft_strtabadd.c ft_strtabdel.c ft_strndup.c
WSTR_NAME = ft_wstrlen.c ft_wcharsize.c ft_wstrsize.c ft_wcharcpy.c ft_wstrsizecpy.c ft_wstrcpy.c ft_wstrdup.c

SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = $(addprefix -I ,$(INC_PATH))

SRC_NAME = $(CONV_NAME) $(FILE_NAME) $(FT_PRINTF) $(IS_NAME) $(LST_NAME) $(MAT_NAME) $(MEM_NAME) $(NBR_NAME) $(PUT_NAME) $(STR_NAME) $(WSTR_NAME)
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


all: $(NAME)

$(NAME): $(OBJ) $(INC_PATH)*.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

wclean:
	rm -fv $(SRC_PATH)*~ $(INC_PATH)*~ ./*~ ./a.out ./*.c

re: fclean all

norme:
	norminette $(SRC) $(INC_PATH)*.h

.PHONY: clean fclean all norme re
