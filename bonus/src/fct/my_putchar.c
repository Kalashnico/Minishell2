/*
** my_putchar.c for my_putchar in /home/guerin_n/Epitech/Shell/PSU_2016_minishell1/src/fct
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Mon Jan  9 15:48:33 2017 Nicolas Guerin
** Last update Wed Apr  5 03:59:50 2017 Nicolas
*/

#include "prototypes.h"

void	my_putchar(char c, int fd, char *color)
{
  write(fd, color, my_strlen(color));
  write(fd, &c, 1);
  write(fd, WHITE, my_strlen(WHITE));
}
