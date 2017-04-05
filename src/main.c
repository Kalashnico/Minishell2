/*
** main.c for main in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 06:15:14 2017 Nicolas
** Last update Wed Apr  5 04:12:28 2017 Nicolas
*/

#include "prototypes.h"

void	prompt()
{
  my_putstr("Kalashnico @ PC : ", 0, CYAN);
}

int	main(int ac,__attribute__ ((unused)) char **av, char **env)
{
  char	*buff;
  char	**new_av;

  if (ac != 1)
    return (84);
  prompt();
  signal_process();
  while ((buff = get_next_line(0)) != NULL)
    {
      if ((buff = epur_str(buff)) == NULL ||
	  (new_av = my_str_to_wordtab(buff, ' ')) == NULL ||
	  (my_memcmp("exit", buff, 4) == 0))
	return (0);
      if (check_if_built_exist(buff) == 0)
	{
	  if ((builtin(buff, env)) == 84 ||
	      (env = builtin_env(buff, env)) == NULL)
	    my_putstr("Error in the execution of the command\n", 2, RED);
	}
      else
	{
	  if ((my_execve_brut(buff, new_av, env)) == 84)
	    if (my_execve(new_av, env) == 84 && my_strlen(buff) != 0)
	      my_putstr("Minishell2: Command not found\n", 2, RED);
	}
      free_tab(new_av);
      free(buff);
      prompt();
    }
  if (buff == NULL)
    return (84);
  return (0);
}
