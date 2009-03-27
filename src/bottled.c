/**
 * bottled - famous bottle counting task 
 * implemented as xinetd (or inetd) daemon.
 *
 * anonymous, 2009
 * vim:ts=2:sw=2:expandtab:cindent
 *
 * placed to public domain
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CACHE_SIZE  9

#define MESSAGE     "%02i bottles of beer on the wall\r\n"\
                    "%02i bottles of beer!\r\n"\
                    "Take on down, and pass it around!\r\n"\
                    "%s bottles of beer on the wall\r\n\r\n"

#define MSG_SIZE    sizeof(MESSAGE)-5

int main(int argc, char **argv)
{
  int counter = CACHE_SIZE;
  /* Zero value workaround value */
  char wa_zero[3] = "Er";

  if(argc == 2) 
    counter = atoi(argv[1]);

  if(!counter)
    exit(EXIT_FAILURE);

  while(counter) {
    if(counter-1) 
      sprintf(wa_zero,"%02i",counter-1);
    else 
      sprintf(wa_zero,"%s","No");
    
    if(printf(MESSAGE, counter, counter, wa_zero) != MSG_SIZE) {
      exit(EXIT_FAILURE);
    }
    fflush(stdout);
    sleep(1);
    counter--;
  }

  return 0;
}
