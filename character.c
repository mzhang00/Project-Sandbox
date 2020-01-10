#include "character.h"
#define FILE = "game.txt"
void char_move() {
  char * command = "cat game.txt";
  while (1) {
    if (getch() == '\033') { // if the first value is esc
      getch(); // skip the [
      switch(getch()) { // the real value
          case 'A':
              // code for arrow up
              break;
          case 'B':
              // code for arrow down
              break;
          case 'C':
              // code for arrow right
              break;
          case 'D':
              // code for arrow left
              break;
      }
  }
}

void draw(int X, int Y) {
  FILE *fptr1, *fptr2;
  int lno, linectr = 0;
  char str[256];
  char newln[MAX] = "";
  fptr1 = fopen(FILE, "r");
  fptr2 = fopen("temp.txt", "w");
  /* get the new line from the user */
  for (int i = 0; i < X -1;i++) {
    if (i == X) {
      strcat(newln, "0 ");
    }
    else {
      strcat(newln, "_ ");
    }
  }
  strcat(newln,"\n");
  newln[strlen(newln) - 1] = '\0';
  /* get the line number to delete the specific line */
  lno = Y + 1;
  // copy all contents to the temporary file other except specific line
  while (!feof(fptr1)) {
     strcpy(str, "\0");
     fgets(str, MAX, fptr1);
     if (!feof(fptr1)) {
       linectr++;
       if (linectr != lno) {
          fprintf(fptr2, "%s", str);
       }
       else {
         fprintf(fptr2, "%s", newln);
       }
     }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove(fname);
  rename(temp, fname);
  return 0;
 }
}
