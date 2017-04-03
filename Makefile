##
## Makefile for makefile in /home/nicolas/Epitech/Shell/PSU_2016_minishell1
## 
## Made by Nicolas
## Login   <nicolas.guerin@epitech.eu>
## 
## Started on  Sun Apr  2 06:15:28 2017 Nicolas
## Last update Mon Apr  3 14:21:55 2017 Nicolas
##

NAME	= mysh

CC	= gcc -g

RM	= rm -f

SRCS	= ./src/builtin/my_cd.c		\
	  ./src/builtin/my_env.c	\
	  ./src/builtin/builtin.c	\
	  ./src/fct/my_memcmp.c		\
	  ./src/fct/get_next_line.c	\
	  ./src/fct/my_putchar.c	\
	  ./src/fct/my_putstr.c		\
	  ./src/fct/my_realloc.c	\
	  ./src/fct/my_str_to_wordtab.c	\
	  ./src/fct/my_strcat.c		\
	  ./src/fct/my_strcpy.c		\
	  ./src/fct/my_strdup.c		\
	  ./src/fct/my_strlen.c		\
	  ./src/fct/show_tab.c		\
	  ./src/my_exec.c		\
	  ./src/main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

LDFLAGS=

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o:	%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
