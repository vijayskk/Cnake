#include "../lib/enableRaw.h"
#include "../lib/setupPlayGround.h"
#include "../lib/input.h"
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

    

    while (1)
    {
        int input = takeInput();
    }
    
    
    
    return 0;
}
