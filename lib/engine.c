#include "defenitions.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int score = 0;
int highscore = 0;
int restart = 0;
struct Frame{
    char framedata[HEIGHT][WIDTH];
};

void setScore(){
    score++;
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
    sprintf(buffer,"                            ");
    sprintf(buffer,"\x1b[%d;1H\nHIGH: %d",HEIGHT+1,highscore);
    write(STDOUT_FILENO, buffer , 20);
    return 0;
}

void gameOver(){
    write(STDOUT_FILENO, "\x1b[2J", 4);
    char * buffer = malloc(sizeof(char) * 5);
    if (score > highscore)
    {
        sprintf(buffer,"\x1b[%d;%dH\nNEW HIGH SCORE!!!!",(HEIGHT/2) -2 ,WIDTH/2);
        write(STDOUT_FILENO, buffer , 30);
    }
    sprintf(buffer,"\x1b[%d;%dH\nGame Over...",HEIGHT/2,WIDTH/2);
    write(STDOUT_FILENO, buffer , 30);
    sprintf(buffer,"                            ");
    sprintf(buffer,"\x1b[%d;%dHSCORE: %d",(HEIGHT/2) + 3,WIDTH/2,score);
    write(STDOUT_FILENO, buffer , 30);
    sprintf(buffer,"                            ");
    sprintf(buffer,"\x1b[%d;%dHPress R to retry X to quit",(HEIGHT/2) + 5,WIDTH/2);
    write(STDOUT_FILENO, buffer , 50);

    while(1){
        char ch = '\0';
        read(STDIN_FILENO, &ch, 1);

        if (ch == 'x')
        {
            exit(0);
        }
        if (ch == 'r'){
            if (score>highscore)
            {
                highscore = score;
            }
            score = 0;
            
            restart = 1;
            break;
        }
    }
}