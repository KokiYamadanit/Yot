#ifndef YATZY_H
#define YATZY_H

struct point
{
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int chance;
    int fourcard;
    int fullhouse;
    int ss;
    int bs;
    int yot;
    int sum;
    int bonus;
};

extern int hand[5];

void shuffle();
void show();
void exchange();
void sort();
int isOne();
int isTwo();
int isThree();
int isFour();
int isFive();
int isSix();
int isChance();
int isFourCard();
int isFullhouse();
int isSS();
int isBS();
int isYot();
void judge(struct point *a);
void Onepoint(struct point *a);
void Twopoint(struct point *a);
void Threepoint(struct point *a);
void Fourpoint(struct point *a);
void Fivepoint(struct point *a);
void Sixpoint(struct point *a);
void Chancepoint(struct point *a);
void FourCardpoint(struct point *a);
void Fullhousepoint(struct point *a);
void SSpoint(struct point *a);
void BSpoint(struct point *a);
void Yotpoint(struct point *a);
void selecting(struct point *a);
void play(struct point *a);
void quickreset(struct point *a);
void pointed(struct point *a);
void sum(struct point *a);
void show_scores(struct point *a, struct point *b);
void print_score(struct point *a, struct point *b);

#endif
