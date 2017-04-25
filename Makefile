##
## Makefile for makefile in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
## 
## Made by Nicolas
## Login   <nicolas.guerin@epitech.eu>
## 
## Started on  Wed Apr  5 01:04:14 2017 Nicolas
## Last update Tue Apr 25 14:58:48 2017 Nicolas
##


GREEN   = \033[1;32m

RED     = \033[1;31m

YELLOW  = \033[1;33m

WHITE   = \033[0;m

NAME	= mysh

CC	= gcc -g

RM	= rm -f

SRCS	= ./src/builtin/builtin.c		\
	  ./src/builtin/my_cd.c			\
	  ./src/builtin/my_env.c		\
	  ./src/builtin/my_setenv.c		\
	  ./src/builtin/my_unsetenv.c		\
	  ./src/builtin/my_pwd.c		\
	  ./src/builtin/my_cd_home_exec.c	\
	  ./src/execve/find_if_exist.c		\
	  ./src/execve/my_exec.c		\
	  ./src/execve/my_exec_brut.c		\
	  ./src/execve/wait_pid_exec.c		\
	  ./src/fct/find_pos_equal.c		\
	  ./src/fct/my_strcmp.c			\
	  ./src/fct/my_getnbr.c			\
	  ./src/fct/my_memset.c			\
	  ./src/fct/epur_str.c			\
	  ./src/fct/count_word.c		\
	  ./src/fct/free_tab.c			\
	  ./src/fct/count_colums.c		\
	  ./src/fct/get_next_line.c		\
	  ./src/fct/count_pipe.c		\
	  ./src/fct/my_str_isalpha.c		\
	  ./src/fct/my_memcmp.c			\
	  ./src/fct/my_putchar.c		\
	  ./src/fct/my_putstr.c			\
	  ./src/fct/my_realloc.c		\
	  ./src/fct/copy_tab.c			\
	  ./src/fct/my_str_to_wordtab.c		\
	  ./src/fct/my_strcat.c			\
	  ./src/fct/my_strcpy.c			\
	  ./src/fct/my_strdup.c			\
	  ./src/fct/my_strlen.c			\
	  ./src/fct/my_strncmp.c		\
	  ./src/fct/my_strlen_tab.c		\
	  ./src/fct/show_tab.c			\
	  ./src/signal/get_sigint.c		\
	  ./src/signal/signal_process.c		\
	  ./src/main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)
	make -C bonus

$(NAME): $(OBJS)
	 @$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 @printf "\n[$(GREEN)OK$(WHITE)] Binary : $(NAME)\n"
	 @echo "-------------------\n"

%.o :    %.c
	 @$(CC) $(CFLAGS) -c -o $@ $<
	 @printf "[$(GREEN)OK$(WHITE)] $<\n"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
