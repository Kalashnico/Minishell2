/*
** get_sigint.c for get_sigint in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/signal
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 00:08:35 2017 Nicolas
** Last update Sun Apr  9 02:49:04 2017 Nicolas
*/

#include "prototypes.h"

void	get_sigint(int sigint)
{
  (void)sigint;
  my_putstr("\nKalashnico @ PC : ", 0, CYAN);
}
