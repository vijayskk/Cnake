#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include "../lib/defenitions.h"

int getWindowSize(int *rows, int *cols)
{
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
  {
    return -1;
  }
  else
  {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return 0;
  }
}

int validatePlayGround()
{
  int row, col;
  getWindowSize(&row, &col);
  char buf[50];
  if (row < HEIGHT || col < WIDTH)
  {
      sprintf(buf, "Cannot Play game\nResize the window and run again.");
      write(STDOUT_FILENO, buf, strlen(buf));
      return 1;
  }else{
      char buf[10];
      sprintf(buf,"%d x %d",row,col);
      write(STDOUT_FILENO, buf, strlen(buf));
      return 0;
  }
}

void setup(int * hold)
{
  write(STDOUT_FILENO, "\x1b[2J", 4);
  write(STDOUT_FILENO, "\x1b[?25l", 6);
  * hold = validatePlayGround();
}