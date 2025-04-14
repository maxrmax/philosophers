# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 16:10:04 by mring             #+#    #+#              #
#    Updated: 2025/04/14 16:15:50 by mring            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosophers
CFLAGS		= -Wall -Wextra -Werror

SRC			= main parsing
SRCS		= $(addsuffix .c, $(SRC))

OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: ${NAME}

$(OBJ_DIR)/%.o: %.c
				@$(CC) ${CFLAGS} -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

${NAME}: 		$(OBJ_DIR) $(OBJS)
				@$(CC) $(OBJS) -o $(NAME)
				@echo "/// compiled: $(NAME) ///"

clean:
				@rm -rf ${OBJ_DIR}
				@echo "/// cleaning.. ///"

fclean: 		clean
				@rm -f ${NAME}

re: 			fclean all

.PHONY:			all clean fclean re