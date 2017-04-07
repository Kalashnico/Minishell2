/*
** find_pos_equal.c for find_pos_equal in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Thu Apr  6 00:34:23 2017 Nicolas
** Last update Thu Apr  6 23:57:12 2017 Nicolas
*/

int	find_pos_equal(char *path)
{
  int	i;

  i = 0;
  while (path && path[i] != '=')
    i++;
  i++;
  return (i);
}
