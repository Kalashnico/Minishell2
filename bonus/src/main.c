/*
** main.c for main in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 06:15:14 2017 Nicolas
** Last update Fri Apr  7 17:53:55 2017 Nicolas
*/

#include "prototypes.h"

void	prompt()
{
  my_putstr("Kalashnico @ PC : ", 0, CYAN);
}

void	my_exit()
{
  my_putstr("Goodbye Kalashnico, I hope you enjoyed staying", 0, GREEN);
  my_putstr(" with us!\n\nSee you soon.\n", 0, GREEN);
}

char	**mysh(char **env, char *buff, char **new_av, int *ret)
{
  if (check_if_built_exist(buff) == 0)
    {
      if ((builtin(buff, env)) == 84 ||
	  (env = builtin_env(buff, env, ret)) == NULL)
	my_putstr("Error in the execution of the command\n", 2, RED);
    }
  else
    {
      if ((my_execve_brut(buff, new_av, env)) == 84)
	if (my_execve(new_av, env) == 84 && my_strlen(buff) != 0)
	  {
	    my_putstr(new_av[0], 2, YELLOW);
	    my_putstr(": Command not found.\n", 2, RED);
	   *ret = 1;
	  }
    }
  free_tab(new_av);
  free(buff);
  prompt();
  return (env);
}

int	init_shell(int ac)
{
  if (ac != 1)
    return (84);
  my_putstr("----------------------------------------------\n", 0, GREEN);
  my_putstr("|                                            |\n", 0, GREEN);
  my_putstr("| Welcome to your shell Kalashnico.          |\n", 0, GREEN);
  my_putstr("| How was your day without coding ?          |\n", 0, GREEN);
  my_putstr("|                                            |\n", 0, GREEN);
  my_putstr("|                                            |\n", 0, GREEN);
  my_putstr("|                             minishell_2.0.3|\n", 0, GREEN);
  my_putstr("----------------------------------------------\n\n\n", 0, GREEN);
  prompt();
  if (signal(SIGINT, &get_sigint) == SIG_ERR)
    my_putstr("ERROR_SIGNAL\n", 2, RED);
  return (0);
}

int	main(int ac,__attribute__ ((unused)) char **av, char **env)
{
  char	*buff;
  char	**new_av;
  int	ret;

  if ((init_shell(ac)) == 84)
    return (my_putstr("Too many arguments !\n", 2, RED), 84);
  ret = 0;
  while ((buff = get_next_line(0)) != NULL)
    {
      if (count_pipe(buff) < 2)
	{
	  if ((buff = epur_str(buff)) == NULL ||
	      (new_av = my_str_to_wordtab(buff, ' ')) == NULL)
	    return (84);
	  if ((my_strcmp("exit", new_av[0]) == 0))
	    return (my_exit(), my_getnbr(new_av[1]));
	  if ((env = mysh(env, buff, new_av, &ret)) == NULL)
	    return (84);
	}
      else
	prompt();
    }
  free(new_av);
  return (ret);
}
