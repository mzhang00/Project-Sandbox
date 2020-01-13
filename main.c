#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include "proto.h"
#include "string.h"

int server_sockfd = 0, client_sockfd = 0;
ClientList *root, *now;


int main(int argc, char * argv[]){
  printf("Please enter your name: ");
  char nickname[500];
  fgets(nickname, 500, stdin);
  printf("Connected %s", nickname);
  while (1){
    char name[500];
    if (argc > 1) {
      strcpy(name, argv[1]);
    }else{
      fgets(name, 500, stdin);
      int i = 0;
      while (name[i] != '\n') {
        i++;
      }
      name[i] = '\0';
    }
    printf("%s\n", name);
  }
  // https://github.com/lovenery/c-chatroom/blob/master/src/client.c
  sockfd = socket(AF_INET , SOCK_STREAM , 0);

  return 0;
}
