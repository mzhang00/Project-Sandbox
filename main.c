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
  int file;
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

    if (strcmp(name, "check") == 0){
      //printf("test\n");
      // file = open("log.txt", O_RDWR);
      // //printf("test\n");
      // char line [500];
      // printf("%ld\n", read(file, line, 500));
      // while (read(file, line, 500) > 0) {
      //     printf("test\n");
      //     printf("%s\n",line);
      // }
      // close(file);
      FILE *f = fopen("log.txt", "r");
      char str[500];
      while (fgets(str, 500, f) != NULL){
        printf("%s\n", str);
      }
      fclose(f);

    }else{
      FILE *f = fopen("log.txt", "a");

      fprintf(f, "%s\n", name + nickname);

      fclose(f);

      //printf("%s\n", name);
      // char line [500];
      // read(file, line, 500);
      // printf("%s\n",line);
      //
      // close(file);
      //printf("%s\n", name);
    }

  }
  // https://github.com/lovenery/c-chatroom/blob/master/src/client.c
  return 0;
}
