/*
** main.c for main in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 06:15:14 2017 Nicolas
** Last update Sun Apr  9 02:56:56 2017 Nicolas
*/

#include "prototypes.h"

char	**my_exit(char *str)
{
  my_putstr("Goodbye Kalashnico, I hope you enjoyed staying", 0, GREEN);
  my_putstr(" with us!\n\nSee you soon.\n", 0, GREEN);
  exit(my_getnbr(str));
  return (NULL);
}
