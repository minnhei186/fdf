# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:49:56 by dhosokaw          #+#    #+#              #
#    Updated: 2024/07/27 16:04:10 by dhosokaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc 
CFLAGS=-Wall -Wextra -Werror
INCDIR=-Iinclude
FRAMEWORKS = -lX11 -lXext -lm -lbsd

LIBFTDIR=libft
LIBMINIDIR=minilibx

SRCS=src/color.c \
	src/data_loder.c \
	src/data_loder_error.c \
	src/data_loder_utils.c \
	src/draw.c \
	src/error_utils.c \
	src/fdf.c \
	src/hook.c \
	src/line_draw.c \
	src/memory_free.c \
	src/my_mlx_utils.c \
	src/read_map.c \
	src/utils.c

OBJS=$(SRCS:.c=.o)

LIB_ft=libft.a
LIB_mini=libmlx.a
NAME=fdf


all:$(LIB_ft) $(LIB_mini) $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTDIR)/$(LIB_ft)  $(LIBMINIDIR)/$(LIB_mini) $(FRAMEWORKS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -g -c $< -o $@

$(LIB_ft):
	$(MAKE) -C $(LIBFTDIR)
$(LIB_mini):
	$(MAKE) -C $(LIBMINIDIR)


clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(LIBMINIDIR)
	rm -rf $(OBJS)
fclean:clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re
