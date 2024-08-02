#include "engine.c"
#include <stdlib.h>
#include "defenitions.h"
#include "../lib/input.h"

void drawSnake(void);
void controlSnake(int);
enum Direction{
    UP,DOWN,LEFT,RIGHT
};
struct Snake
{
    int len;
    int x;
    int y;
    enum Direction dir;
};
struct Snake *snake;
struct Frame *frame;
int trail[100][2];
void drawWalls()
{
    frame = (struct Frame *)malloc(sizeof(struct Frame));
    snake = (struct Snake *)malloc(sizeof(struct Snake));
    snake->len = 3;
    snake->x = (int)(WIDTH / 2);
    snake->y = (int)(HEIGHT / 2);
    snake->dir = UP;
    frame->framedata[snake->y][snake->x] = 'O';
    for (int i = 0; i < WIDTH; i++)
    {
        frame->framedata[0][i] = 'X';
        frame->framedata[HEIGHT - 1][i] = 'X';
    }
    for (int i = 0; i < HEIGHT; i++)
    {
        frame->framedata[i][0] = 'X';
        frame->framedata[i][WIDTH - 1] = 'X';
    }
    render(frame);
}

void drawSnake()
{
    //frame->framedata[snake->y][snake->x] = ' ';
    frame->framedata[trail[snake->len-1][1]][trail[snake->len-1][0]] = ' ';

        trail[0][0] = snake->x;
        trail[0][1] = snake->y;
        int j;    

        
        for(j = snake->len; j > 0; j--){    
            trail[j][1] = trail[j-1][1];
            trail[j][0] = trail[j-1][0];    
        }    

    
    

    

    int inp = takeInput();
    controlSnake(inp);
    if (snake->dir == UP && snake->y > 0)
    {
        //frame->framedata[snake->y][snake->x] = ' ';
        snake->y--;
        frame->framedata[snake->y][snake->x] = 'O';
        render(frame);
    }
    else if (snake->dir == DOWN && snake->y < HEIGHT - 1)
    {
        //frame->framedata[snake->y][snake->x] = ' ';
        snake->y++;
        frame->framedata[snake->y][snake->x] = 'O';
        render(frame);
    }
    else if (snake->dir == LEFT && snake->x > 0)
    {
        //frame->framedata[snake->y][snake->x] = ' ';
        snake->x--;
        frame->framedata[snake->y][snake->x] = 'O';
        render(frame);
    }
    else if (snake->dir == RIGHT && snake->x < WIDTH - 1)
    {
        //frame->framedata[snake->y][snake->x] = ' ';
        snake->x++;
        frame->framedata[snake->y][snake->x] = 'O';
        render(frame);
    }
    else
    {
        frame->framedata[snake->y][snake->x] = 'O';
        //render(frame);
    }
}

void controlSnake(int inp){
    switch (inp)
    {
    case ARROWUPKEY:
        if (snake->dir != DOWN)
        {
            snake->dir = UP;
        }
        break;
    case ARROWDOWNKEY:
        if (snake->dir != UP)
        {
            snake->dir = DOWN;
        }
        break;
    case ARROWLEFTKEY:
        if (snake->dir != RIGHT)
        {
            snake->dir = LEFT;
        }
        break;
    case ARROWRIGHTKEY:
        if (snake->dir != LEFT)
        {
            snake->dir = RIGHT;
        }
        break;
    default:
        break;
    }
}