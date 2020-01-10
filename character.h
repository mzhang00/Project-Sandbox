#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <conio.h>

struct unit {
  int number;
  int health;
  int weapon_id;
  int moves_left;
  int x;
  int y;
};
void char_move();
void draw(int X, int Y);
