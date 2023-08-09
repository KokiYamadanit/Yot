#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "yatzy.h"

int main(void)
{
    hand[0] = 1;
    hand[1] = 2;
    hand[2] = 3;
    hand[3] = 4;
    hand[4] = 5;
    sort();

    assert(isOne() && isTwo() && isThree() && isFour() && isFive() && isSS() && isBS() && isChance() == 1);

    hand[0] = 6;
    hand[1] = 6;
    hand[2] = 6;
    hand[3] = 6;
    hand[4] = 5;
    sort();
    assert(isFive() && isSix() && isFourCard() && isChance() == 1);

    hand[0] = 6;
    hand[1] = 6;
    hand[2] = 6;
    hand[3] = 6;
    hand[4] = 6;
    sort();
    assert(isSix() && isFourCard() && isYot() && isChance() == 1);

    hand[0] = 2;
    hand[1] = 4;
    hand[2] = 5;
    hand[3] = 4;
    hand[4] = 3;
    sort();
    assert(isTwo() && isThree() && isFour() && isFive() && isSS() && isChance() == 1);

    printf("test clear\n");

    return 0;
}