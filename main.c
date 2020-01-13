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

int main(int argc, char * argv[]){
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
  return 0;
}
