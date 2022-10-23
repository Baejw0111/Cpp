#ifndef PLAYER_CPP
#define PLAYER_CPP
#include "Lost City.h"
#include "Deck.cpp"
#include "Pile.cpp"

Player::Player() : score(0) {}

int Player::Score()
{
    int total = 0;

    for (int i = 0; i < 6; i++)
    {
        total += field[i].PileScore();
    }

    score = total;
    return total;
}

#endif