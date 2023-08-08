#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int hand[5];

void sort()
{
    int tmp;

    for (int k = 0; k < 5; k++)
    {
        for (int j = k + 1; j < 5; j++)
        {
            if (hand[k] > hand[j])
            {
                tmp = hand[k];
                hand[k] = hand[j];
                hand[j] = tmp;
            }
        }
    }
}

/*一の目*/
int isOne()
{
    if (hand[0] == 1 || hand[1] == 1 || hand[2] == 1 || hand[3] == 1 || hand[4] == 1)
    {
        return 1;
    }
    return 0;
}

/*二の目*/
int isTwo()
{
    if (hand[0] == 2 || hand[1] == 2 || hand[2] == 2 || hand[3] == 2 || hand[4] == 2)
    {
        return 1;
    }
    return 0;
}

/*三の目*/
int isThree()
{
    if (hand[0] == 3 || hand[1] == 3 || hand[2] == 3 || hand[3] == 3 || hand[4] == 3)
    {
        return 1;
    }
    return 0;
}

/*四の目*/
int isFour()
{
    if (hand[0] == 4 || hand[1] == 4 || hand[2] == 4 || hand[3] == 4 || hand[4] == 4)
    {
        return 1;
    }
    return 0;
}

/*五の目*/
int isFive()
{
    if (hand[0] == 5 || hand[1] == 5 || hand[2] == 5 || hand[3] == 5 || hand[4] == 5)
    {
        return 1;
    }
    return 0;
}

/*六の目*/
int isSix()
{
    if (hand[0] == 6 || hand[1] == 6 || hand[2] == 6 || hand[3] == 6 || hand[4] == 6)
    {
        return 1;
    }
    return 0;
}

/*チャンス*/
int isChance()
{
    return 1;
}

/*フォーカード*/
int isFourCard()
{
    if (hand[0] == hand[1] && hand[1] == hand[2] && hand[2] == hand[3] ||
        hand[1] == hand[2] && hand[2] == hand[3] && hand[3] == hand[4])
    {
        return 1;
    }
    return 0;
}

/*フルハウス*/
int isFullhouse()
{
    if (hand[0] == hand[1] && hand[2] == hand[3] && hand[3] == hand[4] ||
        hand[0] == hand[1] && hand[1] == hand[2] && hand[3] == hand[4])
    {
        return 1;
    }
    return 0;
}

/*Sストレート*/
int isSS()
{
    int handcopy[6];
    for (int k = 0; k < 6; k++)
    {
        handcopy[k] = 0;
    }

    for (int i = 0; i < 5; i++)
    {
        handcopy[hand[i] - 1] = 1;
    }

    for (int j = 0; j < 3; j++)
    {
        if (handcopy[j] && handcopy[j + 1] && handcopy[j + 2] && handcopy[j + 3])
        {
            return 1;
        }
    }
    return 0;
}

/*Bストレート*/
int isBS()
{
    if (hand[0] + 1 == hand[1] && hand[1] + 1 == hand[2] && hand[2] + 1 == hand[3] && hand[3] + 1 == hand[4])
    {
        return 1;
    }
    return 0;
}

/*ヨット*/
int isYot()
{
    if (hand[0] == hand[1] && hand[1] == hand[2] && hand[2] == hand[3] && hand[3] == hand[4])
    {
        return 1;
    }
    return 0;
}

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