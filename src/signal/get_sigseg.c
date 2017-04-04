/*
** get_sigseg.c for get_sigseg in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/signal
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 00:07:44 2017 Nicolas
** Last update Wed Apr  5 01:20:22 2017 Nicolas
*/

#include "prototypes.h"

void	get_sigseg(int sigint)
{
  (void)sigint;
  my_putstr("\nSegfault.. Learn how to code. :)\n", 2);
  my_putstr("$>", 0);
}
