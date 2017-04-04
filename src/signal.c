/*
** signal.c for signal in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Mon Apr  3 23:08:57 2017 Nicolas
** Last update Mon Apr  3 23:11:33 2017 Nicolas
*/

#include <signal.h>

void  INThandler(int sig)
{
  char  c;

  signal(sig, SIG_IGN);
  printf("OUCH, did you hit Ctrl-C?\n");
}

void  main(void)
{
  signal(SIGINT, INThandler);
  while (1)
    pause();
}
