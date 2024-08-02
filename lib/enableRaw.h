#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
struct termios original;

void disableRawMode(){
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    write(STDOUT_FILENO, "\x1b[?25h", 6);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&original);
}

void enableRawMode(){
    tcgetattr(STDIN_FILENO,&original);
    atexit(disableRawMode);
    struct termios raw = original;

    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}