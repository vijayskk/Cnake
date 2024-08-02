#include "../lib/enableRaw.h"
#include "../lib/setupPlayGround.h"
#include "../lib/gameLogic.h"
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

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
        drawSnake();
        if (restart == 1)
        {
            break;
        }
        
    }
    restart = 0;
    main();

    return 0;
}
