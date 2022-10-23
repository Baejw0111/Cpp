#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

typedef enum
{
    yellow,
    white,
    blue,
    green,
    red,
    purple,
    nothing
} Color; // Color of card

typedef struct Card
{
    Color col;
    int num;
    struct Card *link;
} Card;

using card_ptr = Card *;

class Pile
{ // Pile of cards. Using Stack.
    card_ptr top;

public:
    Pile();
    void Push(card_ptr item);
    card_ptr Pop();
    card_ptr Peek();
    int isEmpty();
    void PileStatus(); // Print the pile status
    int PileScore();   // Calculate and return the pile score
    ~Pile();
};

class Deck
{ // List
    card_ptr head, tail;

public:
    Deck();
    void Add(card_ptr item);
    card_ptr Index(int n);      // Return the card corresponding to the index
    void DeckStatus();          // Print the deck status
    void Remove(card_ptr item); // Remove item from deck
    ~Deck();
};

class Player
{
    int score; // Player's score

public:
    Deck deck;     // Player's deck
    Pile field[6]; // Player's field
    Player();      // Constructor of Player Class
    int Score();   // Calculate and return player's score
    ~Player(){};
};

class OS
{
    Pile DrawPile, DiscardField[6]; // DrawPile: Pile of new card / DiscardField: Field where cards are discarded. Consists of 6 discard piles
    Player P[2];                    // Player 1,2
    Color DiscardedColor;           // for preventing to draw the same card player have just discarded
    int player, draw_num;           // player: current playing player, draw_num: the number of cards in the draw pile

public:
    OS();                            //Initialize game environment
    void FieldStatus(Pile field[6]); // Print current status of Player's field or Discard field
    void Place();                    // discard card or place it on player's field
    void Draw();                     // Draw card from DrawPile or DiscardField
    void DrawNum();                  // Print the number of cards in the draw pile
    void Turn();                     // Tasks to be performed on each player's turn
    int GameEnd();                   // Determining if the game is over
    void WinnerMessage();            // Print who is winner or tie
    ~OS(){};
};

#endif