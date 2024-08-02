#include <unistd.h>
#include "defenitions.h"
#include <errno.h>
#include <stdlib.h>
#define CTRL_KEY(k) ((k) & 0x1f)

int takeInput(){
    char ch = '\0';
    read(STDIN_FILENO, &ch, 1);

    if (read(STDIN_FILENO, &ch, 1) == -1 && errno != EAGAIN) exit(1);
    if (ch == CTRL_KEY('x')) exit(0);

    if(ch == ARROWUPKEY) return ARROWUPKEY;
    if(ch == ARROWDOWNKEY) return ARROWDOWNKEY;
    if(ch == ARROWLEFTKEY) return ARROWLEFTKEY;
    if(ch == ARROWRIGHTKEY) return ARROWRIGHTKEY;
    return 0;
}