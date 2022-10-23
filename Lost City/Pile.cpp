#ifndef PILE_CPP
#define PILE_CPP
#include "Lost City.h"

Pile::Pile() : top(NULL) {}

void Pile::Push(card_ptr item)
{
    if (!top)
    {
        top = item;
        top->link = NULL;
    }
    else
    {
        item->link = top;
        top = item;
    }
}

card_ptr Pile::Pop()
{
    if (!top)
    {
        return top;
    }
    card_ptr tmp = top;
    top = top->link;

    return tmp;
}

card_ptr Pile::Peek()
{
    card_ptr tmp = top;

    return tmp;
}

int Pile::isEmpty()
{
    if (top)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Pile::PileScore()
{
    int score = 0, total = 0, wager = 1;

    if (top != NULL)
    {
        for (card_ptr i = top; i; i = i->link)
        {
            if (i->num == 0)
            {
                wager += 1;
            }
            else
            {
                total += i->num;
            }
        }
        score = wager * (total - 20);
    }

    return score;
}

Pile::~Pile()
{
    while (!top)
    {
        card_ptr tmp = top;
        top = top->link;
        delete tmp;
    }
}

#endif