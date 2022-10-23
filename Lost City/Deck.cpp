#ifndef DECK_CPP
#define DECK_CPP
#include "Lost City.h"

Deck::Deck() : head(NULL), tail(NULL) {}

void Deck::Add(card_ptr item)
{
    if (!head)
    {
        head = item;
        head->link = NULL;
        tail = head;
    }
    else
    {
        tail->link = item;
        tail = item;
        tail->link = NULL;
    }
}

card_ptr Deck::Index(int n)
{
    int index = 0;
    card_ptr tmp;
    for (card_ptr i = head; i; i = i->link, index++)
    {
        if (index == n)
        {
            tmp = i;
            break;
        }
    }

    return tmp;
}

void Deck::DeckStatus()
{
    int c = 0; // for line break of output
    int a = 1;
    for (card_ptr i = head; i; i = i->link, c++, a++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << a << ": ";
        switch (i->col)
        {
        case yellow:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            cout << "|Y ";
            break;

        case white:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << "|W ";
            break;

        case blue:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            cout << "|B ";
            break;

        case green:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "|G ";
            break;

        case red:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "|R ";
            break;

        case purple:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            cout << "|P ";
            break;
        }

        int tmp = i->num;
        if (tmp == 0)
        { // if card's number value is 0, the card is wager card
            cout << " *| ";
        }
        else if (tmp == 10)
        {
            cout << tmp << "| ";
        }
        else
        {
            cout << " " << tmp << "| ";
        }

        if (c == 3)
        { // line break
            cout << "\n"
                 << endl;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "\n"
         << endl;
}

void Deck::Remove(card_ptr item)
{
    card_ptr before = NULL;
    for (card_ptr i = head; i; i = i->link)
    {
        if (i->col == item->col && i->num == item->num)
        {
            if (before == NULL)
            {
                head = head->link;
                break;
            }
            else
            {
                if (i == tail)
                {
                    tail = before;
                }
                before->link = i->link;
                break;
            }
        }
        before = i;
    }
}

Deck::~Deck()
{
    tail = NULL;
    while (!head)
    {
        card_ptr tmp = head;
        head = head->link;
        delete tmp;
    }
}

#endif