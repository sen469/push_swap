# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 15:40:47 by ssawa             #+#    #+#              #
#    Updated: 2025/08/16 16:29:37 by ssawa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################
#            Library Settings          #
########################################

NAME        = push_swap
BONUS_NAME  = checker

LIBFT       = ./incs/libft/libft.a
LIBFT_DIR   = ./incs/libft

########################################
#        Compiler Configuration        #
########################################

CC          = cc
# CFLAGS      = -Wall -Wextra -Werror
CFLAGS      = -Wall -Wextra
INCLUDES    = -I./incs -I$(LIBFT_DIR)

########################################
#       Source & Object Files          #
########################################

SRC = \
	srcs/argv2arr.c \
	srcs/do.c \
	srcs/error_message.c \
	srcs/free.c \
	srcs/init.c \
	srcs/valid.c \
	srcs/lis.c \
	srcs/main.c \
	srcs/node_operation.c \
	srcs/process.c \
	srcs/process_sub.c \
	srcs/commands/do_pa.c \
	srcs/commands/do_pb.c \
	srcs/commands/do_ra.c \
	srcs/commands/do_rb.c \
	srcs/commands/do_rr.c \
	srcs/commands/do_rra.c \
	srcs/commands/do_rrb.c \
	srcs/commands/do_rrr.c \
	srcs/commands/do_sa.c \
	srcs/commands/do_sb.c \
	srcs/commands/do_ss.c \
	srcs/stack_size.c \
	srcs/command.c \
	srcs/utils.c \
	srcs/few_arguments.c \

BSRCS = \
	b_srcs/checker.c \
	b_srcs/judge.c \
	srcs/commands/do_pa.c \
	srcs/commands/do_pb.c \
	srcs/commands/do_ra.c \
	srcs/commands/do_rb.c \
	srcs/commands/do_rr.c \
	srcs/commands/do_rra.c \
	srcs/commands/do_rrb.c \
	srcs/commands/do_rrr.c \
	srcs/commands/do_sa.c \
	srcs/commands/do_sb.c \
	srcs/commands/do_ss.c \
	srcs/free.c \
	srcs/node_operation.c \
	srcs/error_message.c \
	srcs/init.c \
	srcs/valid.c \
	srcs/argv2arr.c \
	srcs/stack_size.c \


OBJDIR   = objs
OBJ      = $(SRC:%.c=$(OBJDIR)/%.o)
BOBJ     = $(BSRCS:%.c=$(OBJDIR)/%.o)

########################################
#               Rules                  #
########################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(BONUS_NAME): $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BOBJ) $(LIBFT)

# Libftビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# オブジェクトファイル作成（ディレクトリも作る）
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJDIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
