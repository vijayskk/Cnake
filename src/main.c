#include "../lib/enableRaw.h"
#include "../lib/setupPlayGround.h"
#include "../lib/gameLogic.h"
//#include "../lib/clk.h"
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/time.h>

int hold = 0;

int main()
{
    enableRawMode();
    setup(&hold);

    if (hold == 0)
    {
        drawWalls();
    }
    
    while (1)
    {
        struct timeval tf;
        gettimeofday(&tf,NULL);
        if (tf.tv_usec % (5 * 1000) == 0)
        {
            drawSnake();
        }
        //delay(5);
    }
    
    return 0;
}
