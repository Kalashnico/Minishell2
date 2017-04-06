##
## Makefile for makefile in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
## 
## Made by Nicolas
## Login   <nicolas.guerin@epitech.eu>
## 
## Started on  Wed Apr  5 01:04:14 2017 Nicolas
## Last update Thu Apr  6 23:53:20 2017 Nicolas
##

NAME	= mysh

CC	= gcc -g

RM	= rm -f

SRCS	= ./src/builtin/builtin.c	\
	  ./src/builtin/my_cd.c		\
	  ./src/builtin/my_env.c	\
	  ./src/builtin/my_setenv.c	\
	  ./src/builtin/my_unsetenv.c	\
	  ./src/builtin/my_pwd.c	\
	  ./src/execve/find_if_exist.c	\
	  ./src/execve/my_exec.c	\
	  ./src/execve/my_exec_brut.c	\
	  ./src/fct/find_pos_equal.c	\
	  ./src/fct/my_strcmp.c		\
	  ./src/fct/my_getnbr.c		\
	  ./src/fct/my_memset.c		\
	  ./src/fct/epur_str.c		\
	  ./src/fct/count_word.c	\
	  ./src/fct/free_tab.c		\
	  ./src/fct/get_next_line.c	\
	  ./src/fct/count_pipe.c	\
	  ./src/fct/my_memcmp.c		\
	  ./src/fct/my_putchar.c	\
	  ./src/fct/my_putstr.c		\
	  ./src/fct/my_realloc.c	\
	  ./src/fct/my_str_to_wordtab.c	\
	  ./src/fct/my_strcat.c		\
	  ./src/fct/my_strcpy.c		\
	  ./src/fct/my_strdup.c		\
	  ./src/fct/my_strlen.c		\
	  ./src/fct/my_strncmp.c	\
	  ./src/fct/my_strlen_tab.c	\
	  ./src/fct/show_tab.c		\
	  ./src/signal/get_sigabrt.c	\
	  ./src/signal/get_sigint.c	\
	  ./src/signal/get_sigseg.c	\
	  ./src/signal/signal_process.c\
	  ./src/main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
