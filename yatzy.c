#include "yatzy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int hand[5];

/*ランダムに自分の最初のダイスを決定する*/
void shuffle()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++)
    {
        hand[i] = rand() % 6 + 1;
    }
    sleep(1);
}

/*ダイスの目を画面表示する*/
void show()
{
    int i;

    printf("[あなたの手]\n");
    printf("  ");
    for (i = 0; i < 5; i++)
    {
        printf("(%d):%d  ", i + 1, hand[i]);
    }
    printf("\n");
}

/*ダイスの目を交換する*/
void exchange()
{
    int input;
    printf("[ダイスの交換]\n");
    for (int i = 0; i < 5; i++)
    {
        srand((unsigned int)time(NULL));
        /* ダイスの目を交換するかどうかの入力を受け付ける */
        printf("%d個目のダイス(%d):%dを交換しますか？(y→1/n→0)", i + 1, i + 1, hand[i]);
        scanf("%d", &input);
        if (input == 1)
        {
            hand[i] = rand() % 6 + 1;
            printf("交換しました\n");
        }
        else if (input == 0)
        {
            printf("保持しました\n");
        }
        else
        {
            /*想定外な入力に対する操作*/
            printf("1もしくは0を入力してください!!!\n");
            i--;
        }
    }
}

/*さいころの目を昇順にソートする*/
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

/*各役の判定*/
void judge(struct point *a)
{
    sort();
    if (isOne() && a->one == 0)
    {
        printf("1の目 → 1\n");
    }

    if (isTwo() && a->two == 0)
    {
        printf("2の目 → 2\n");
    }

    if (isThree() && a->three == 0)
    {
        printf("3の目 → 3\n");
    }

    if (isFour() && a->four == 0)
    {
        printf("4の目 → 4\n");
    }

    if (isFive() && a->five == 0)
    {
        printf("5の目 → 5\n");
    }

    if (isSix() && a->six == 0)
    {
        printf("6の目 → 6\n");
    }

    if (isChance() && a->chance == 0)
    {
        printf("チャンス → 7\n");
    }

    if (isFourCard() && a->fourcard == 0)
    {
        printf("フォーカード → 8\n");
    }

    if (isFullhouse() && a->fullhouse == 0)
    {
        printf("フルハウス → 9\n");
    }

    if (isSS() && a->ss == 0)
    {
        printf("Sストレート → 10\n");
    }

    if (isBS() && a->bs == 0)
    {
        printf("Bストレート → 11\n");
    }

    if (isYot() && a->yot == 0)
    {
        printf("ヨット → 12\n");
    }
    printf("パス → 0\n");
}

/*1の目のポイント*/
void Onepoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == 1)
        {
            a->one += 1;
        }
    }
}

/*2の目のポイント*/
void Twopoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == 2)
        {
            a->two += 2;
        }
    }
}

/*3の目のポイント*/
void Threepoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == 3)
        {
            a->three += 3;
        }
    }
}

/*4の目のポイント*/
void Fourpoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == 4)
        {
            a->four += 4;
        }
    }
}

/*5の目のポイント*/
void Fivepoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == 5)
        {
            a->five += 5;
        }
    }
}

/*6の目のポイント*/
void Sixpoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == 6)
        {
            a->six += 6;
        }
    }
}

/*チャンスのポイント加算*/
void Chancepoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        a->chance += hand[i];
    }
}

/*フォーカードのポイント*/
void FourCardpoint(struct point *a)
{
    if (hand[0] == hand[1] && hand[1] == hand[2] && hand[2] == hand[3])
    {
        for (int i = 0; i < 4; i++)
        {
            a->fourcard += hand[i];
        }
    }

    if (hand[1] == hand[2] && hand[2] == hand[3] && hand[3] == hand[4])
    {
        for (int i = 1; i < 5; i++)
        {
            a->fourcard += hand[i];
        }
    }
}

/*フルハウスのポイント*/
void Fullhousepoint(struct point *a)
{
    for (int i = 0; i < 5; i++)
    {
        a->fullhouse += hand[i];
    }
}

/*Sストレートのポイント*/
void SSpoint(struct point *a)
{
    a->ss = 15;
}

/*Bストレートのポイント*/
void BSpoint(struct point *a)
{
    a->bs = 30;
}

/*ヨットのポイント*/
void Yotpoint(struct point *a)
{
    a->yot = 50;
}

/*役を選択する*/
void selecting(struct point *a)
{
    int snumber;
    printf("役番号を入力してください: ");
    scanf("%d", &snumber);

    /*1が入力されたとき*/
    if (snumber == 1)
    {
        if (isOne() && a->one == 0)
        {
            printf("1の目に入力しました\n");
            Onepoint(a);
            printf("1の目　%d\n", a->one);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*2が入力されたとき*/
    else if (snumber == 2)
    {
        if (isTwo() && a->two == 0)
        {
            printf("2の目に入力しました\n");
            Twopoint(a);
            printf("2の目　%d\n", a->two);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*3が入力されたとき*/
    else if (snumber == 3)
    {
        if (isThree() && a->three == 0)
        {
            printf("3の目に入力しました\n");
            Threepoint(a);
            printf("3の目　%d\n", a->three);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*4が入力されたとき*/
    else if (snumber == 4)
    {
        if (isFour() && a->four == 0)
        {
            printf("4の目に入力しました\n");
            Fourpoint(a);
            printf("4の目　%d\n", a->four);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*5が入力されたとき*/
    else if (snumber == 5)
    {
        if (isFive() && a->five == 0)
        {
            printf("5の目に入力しました\n");
            Fivepoint(a);
            printf("5の目　%d\n", a->five);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*6が入力されたとき*/
    else if (snumber == 6)
    {
        if (isSix() && a->six == 0)
        {
            printf("6の目に入力しました\n");
            Sixpoint(a);
            printf("6の目　%d\n", a->six);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*7が入力されたとき*/
    else if (snumber == 7)
    {
        if (isChance() && a->chance == 0)
        {
            printf("チャンスに入力しました\n");
            Chancepoint(a);
            printf("チャンス　%d\n", a->chance);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*8が入力されたとき*/
    else if (snumber == 8)
    {
        if (isFourCard() && a->fourcard == 0)
        {
            printf("フォーカードに入力しました\n");
            FourCardpoint(a);
            printf("フォーカード　%d\n", a->fourcard);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*9が入力されたとき*/
    else if (snumber == 9)
    {
        if (isFullhouse() && a->fullhouse == 0)
        {
            printf("フルハウスに入力しました\n");
            Fullhousepoint(a);
            printf("フルハウス　%d\n", a->fullhouse);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*10が入力されたとき*/
    else if (snumber == 10)
    {
        if (isSS() && a->ss == 0)
        {
            printf("Sストレートに入力しました\n");
            SSpoint(a);
            printf("Sストレート　%d\n", a->ss);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*11が入力されたとき*/
    else if (snumber == 11)
    {
        if (isBS() && a->bs == 0)
        {
            printf("Bストレートに入力しました\n");
            BSpoint(a);
            printf("Bストレート　%d\n", a->bs);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    /*12が入力されたとき*/
    else if (snumber == 12)
    {
        if (isYot() && a->yot == 0)
        {
            printf("ヨットに入力しました\n");
            Yotpoint(a);
            printf("ヨット　%d\n", a->yot);
        }
        else
        {
            printf("すでに使用した役であるか、可能役ではありません!\n");
            selecting(a);
        }
    }
    printf("\n");
}

void sum(struct point *a)
{
    if ((a->one + a->two + a->three + a->four + a->five + a->six) >= 63)
    {
        a->bonus = 35;
    }

    a->sum = a->one + a->two + a->three + a->four + a->five + a->six + a->chance + a->fourcard + a->fullhouse + a->ss + a->bs + a->yot + a->bonus;
}

/*手の表示、交換、役の選択を行う*/
void play(struct point *a)
{

    shuffle(); // さいころの目をランダムに生成
    show();    // さいころの目を表示

    int x;
    for (int i = 0; i < 2; i++)
    {
        printf("交換しますか？(y → 1/n → 0)");
        scanf("%d", &x);
        if (x == 1)
        {
            sleep(1);
            exchange();
            show();
            pointed(a);
            continue;
        }
        else if (x == 0)
        {
            break;
        }

        printf("1もしくは0を入力してください!!!\n");
        i--;
    }
    printf("役を選択してください!\n");
    judge(a);
}

void quickreset(struct point *a)
{
    a->one = 0;
    a->two = 0;
    a->three = 0;
    a->four = 0;
    a->five = 0;
    a->six = 0;
    a->chance = 0;
    a->fourcard = 0;
    a->fullhouse = 0;
    a->ss = 0;
    a->bs = 0;
    a->yot = 0;
    a->sum = 0;
    a->bonus = 0;
}

/*獲得済み役を表示*/
void pointed(struct point *a)
{
    printf("使用済み役\n");
    if (a->one != 0)
    {
        printf("1の目　");
    }

    if (a->two != 0)
    {
        printf("2の目　");
    }

    if (a->three != 0)
    {
        printf("3の目　");
    }

    if (a->four != 0)
    {
        printf("4の目　");
    }

    if (a->five != 0)
    {
        printf("5の目　");
    }

    if (a->six != 0)
    {
        printf("6の目　");
    }

    if (a->chance != 0)
    {
        printf("チャンス　");
    }

    if (a->fourcard != 0)
    {
        printf("フォーカード　");
    }

    if (a->fullhouse != 0)
    {
        printf("フルハウス　");
    }

    if (a->ss != 0)
    {
        printf("Ｓストレート　");
    }

    if (a->bs != 0)
    {
        printf("Ｂストレート　");
    }

    if (a->yot != 0)
    {
        printf("ヨット　");
    }
    printf("\n");
}

/*結果表示*/
void show_scores(struct point *a, struct point *b)
{
    printf("\nResult\n");

    if (a->sum > b->sum)
    {
        printf("勝者: Player1\n");
    }
    else if (a->sum < b->sum)
    {
        printf("勝者: Player2\n");
    }
    else
    {
        printf("引き分け\n");
    }
}

void print_score(struct point *a, struct point *b)
{
    FILE *fp;
    int ch;
    char filename[60];

    printf("リザルト入力ファイル名:");
    scanf("%s", filename);

    // ファイルオープン処理
    fp = fopen(filename, "w");
    fprintf(fp, "%-20s%-10s%-10s\n", "役", "Player1", "Player2");
    fprintf(fp, "%-20s%-10d%-10d\n", "１の目", a->one, b->one);
    fprintf(fp, "%-20s%-10d%-10d\n", "２の目", a->two, b->two);
    fprintf(fp, "%-20s%-10d%-10d\n", "３の目", a->three, b->three);
    fprintf(fp, "%-20s%-10d%-10d\n", "４の目", a->four, b->four);
    fprintf(fp, "%-20s%-10d%-10d\n", "５の目", a->five, b->five);
    fprintf(fp, "%-20s%-10d%-10d\n", "６の目", a->six, b->six);
    fprintf(fp, "%-20s%-10d%-10d\n", "チャンス", a->chance, b->chance);
    fprintf(fp, "%-20s%-10d%-10d\n", "フォーカード", a->fourcard, b->fourcard);
    fprintf(fp, "%-20s%-10d%-10d\n", "フルハウス", a->fullhouse, b->fullhouse);
    fprintf(fp, "%-20s%-10d%-10d\n", "Ｓストレート", a->ss, b->ss);
    fprintf(fp, "%-20s%-10d%-10d\n", "Ｂストレート", a->bs, b->bs);
    fprintf(fp, "%-20s%-10d%-10d\n", "ヨット", a->yot, b->yot);
    fprintf(fp, "%-20s%-10d%-10d\n", "ボーナス", a->bonus, b->bonus);
    fprintf(fp, "%-20s%-10s%-10s\n", "合計", "p1", "p2");
    fprintf(fp, "%-20s%-10d%-10d\n", "合計", a->sum, b->sum);
    fclose(fp);
}