#include <stdio.h>
#include <stdlib.h>
#include "yatzy.h"

int main(void)
{
    struct point a;
    struct point b;
    quickreset(&a);
    quickreset(&b);
    char player1[60];
    char player2[60];
    int hand[5];

    /*役が埋まるまでゲームをする*/
    for (int j = 0; j < 12; j++)
    {
        //printf("%d回目\n", j + 1);
        printf("Player1:%s\n", player1);
        pointed(&a);
        play(&a);
        selecting(&a);
        printf("Next player\nPlayer2:%s\n", player2);
        pointed(&b);
        play(&b);
        selecting(&b);
    }

    sum(&a);
    sum(&b);

    show_scores(&a, &b);

    return 0;
}