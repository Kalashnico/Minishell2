/*
** get_sigabrt.c for sig_abrt in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/signal
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 02:45:26 2017 Nicolas
** Last update Wed Apr  5 04:06:19 2017 Nicolas
*/

#include "prototypes.h"

void	get_sigabrt(int sigint)
{
  (void)sigint;
  my_putstr("\nCore dumped.. Learn how to code!\n", 2, RED);
  prompt();
}
