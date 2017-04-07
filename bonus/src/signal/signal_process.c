/*
** signal_process.c for signal_process in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/signal
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 00:09:38 2017 Nicolas
** Last update Fri Apr  7 06:17:57 2017 Nicolas
*/

#include "prototypes.h"

void	signal_process(int status)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	my_putstr("Segmentation fault", 2, YELLOW);
      else if (WTERMSIG(status) == SIGFPE)
	my_putstr("Floating exception", 2, YELLOW);
      else if (WTERMSIG(status) == SIGABRT)
	my_putstr("Abort", 2, YELLOW);
      if (WCOREDUMP(status))
	my_putstr(" (core dumped)", 2, YELLOW);
      my_putchar('\n', 2, YELLOW);
    }
}
