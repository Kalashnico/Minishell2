/*
** main.c for main in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 06:15:14 2017 Nicolas
** Last update Wed Apr  5 04:31:08 2017 Nicolas
*/

#include "prototypes.h"

void	prompt()
{
  my_putstr("Kalashnico @ PC : ", 0, CYAN);
}

void	my_exit()
{
  my_putstr("Goodbye, I hope you enjoyed staying with us!\n", 0, GREEN);
}

void	init_shell()
{
  system("clear");
  my_putstr("----------------------------------------------\n", 0, GREEN);
  my_putstr("|                                            |\n", 0, GREEN);
  my_putstr("| Welcome to your shell Kalashnico.          |\n", 0, GREEN);
  my_putstr("| How was your day without coding ?          |\n", 0, GREEN);
  my_putstr("|                                            |\n", 0, GREEN);
  my_putstr("|                                            |\n", 0, GREEN);
  my_putstr("|                             minishell_2.0.3|\n", 0, GREEN);
  my_putstr("----------------------------------------------\n\n\n", 0, GREEN);
  prompt();
}
  
  
int	main(int ac,__attribute__ ((unused)) char **av, char **env)
{
  char	*buff;
  char	**new_av;

  if (ac != 1)
    return (my_putstr("Too many arguments !\n", 0, RED), 84);
  init_shell();
  signal_process();
  while ((buff = get_next_line(0)) != NULL)
    {
      if ((buff = epur_str(buff)) == NULL ||
	  (new_av = my_str_to_wordtab(buff, ' ')) == NULL ||
	  (my_memcmp("exit", buff, 4) == 0))
	return (my_exit(), 0);
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
