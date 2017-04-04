/*
** my_exec_brut.c for my_exec_brut in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Tue Apr  4 05:03:20 2017 Nicolas
** Last update Tue Apr  4 05:28:27 2017 Nicolas
*/

#include "prototypes.h"

int	my_execve_brut(char *path, char **av, char **env)
{
  pid_t	pid;
  int	status;

  if (find_if_exist(path) == 84)
    return (84);
  if ((pid = fork()) == -1)
    return (84);
  if (pid == 0)
    if ((execve(path, av, env)) == -1)
      return (84);
  wait(&status);
  return (0);
}
