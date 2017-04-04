/*
** main.c for main in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 06:15:14 2017 Nicolas
** Last update Tue Apr  4 02:40:57 2017 Nicolas
*/

#include "prototypes.h"

void	free_tab(char **tab)
{
  int	i;
  
  i = 0;
  while (tab && tab[i])
    free(tab[i++]);
  free(tab[i]);
}

void	get_sigseg(int sigint)
{
  (void)sigint;
  my_putstr("\nSegfault.. Learn how to code. :)\n", 2);
  my_putstr("$>", 0);
}

void	get_sigint(int sigint)
{
  (void)sigint;
  my_putstr("\n$>", 0);
}

void		signal_process()
{
  if (signal(SIGINT, &get_sigint)== SIG_ERR)
    my_putstr("ERROR_SIGNAL\n", 2);
  if (signal(SIGSEGV, get_sigseg) == SIG_ERR)
    my_putstr("ERROR_SIGNAL\n", 2);
}

int	main(int ac,  __attribute__ ((unused)) char **av, char **env)
{
  char	*buff;
  char	**new_av;

  if (ac != 1)
    return (84);
  my_putstr("$>", 0);
  signal_process();
  while ((buff = get_next_line(0)) != NULL)
    {
      if ((new_av = my_str_to_wordtab(buff, ' ')) == NULL ||
	  (my_memcmp("exit", buff, 4) == 0))
	exit(0);
      if (check_if_built_exist(buff) == 0)
	{
	  if ((builtin(buff, env)) == 84 ||
	      (env = builtin_env(buff, env)) == NULL)
	    my_putstr("Error in the execution of the command\n", 2);
	}
      else
	if (my_execve(new_av, env) == 84 && my_strlen(buff) != 0)
	  my_putstr("Minishell2: Command not found\n", 2);
      free_tab(new_av);
      free(buff);
      my_putstr("$>", 0);
    }
  if (buff == NULL)
    my_putchar('\n', 1);
  return (0);
}
