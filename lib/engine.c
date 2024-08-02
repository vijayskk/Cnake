#include "defenitions.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int score = 999;

struct Frame{
    char framedata[HEIGHT][WIDTH];
};

void setScore(int s){
    score = s;
}

int render(struct Frame * frame){
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    for (int row = 0; row < HEIGHT; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (frame->framedata[row][col] < 127 && frame->framedata[row][col] > 32)
            {
                char buf[2];
                sprintf(buf,"%c",frame->framedata[row][col]);
                write(STDOUT_FILENO, buf , 1);
            }else{
                write(STDOUT_FILENO, " " , 1);
            }
        }
        write(STDOUT_FILENO, "\n" , 1);
        char buf[10];
        sprintf(buf,"\x1b[%d;1H",row+2);
        write(STDOUT_FILENO, buf , 7);

        
    }
    char * buffer = malloc(sizeof(char) * 5);
    sprintf(buffer,"\x1b[%d;1H\nSCORE: %d",HEIGHT,score);
    write(STDOUT_FILENO, buffer , 20);
    return 0;
}