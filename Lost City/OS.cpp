#ifndef OS_CPP
#define OS_CPP
#include "Lost City.h"
#include "Deck.cpp"
#include "Pile.cpp"
#include "Player.cpp"

OS::OS()
{
    // game initialize
    draw_num = 72;
    player = 0;
    DiscardedColor = nothing;

    Card c[72]; // All playing cards
    int p = 0;  // index of c

    for (int i = yellow; i <= purple; i++)
    {
        for (int j = 0; j < 12; j++, p++)
        {
            c[p].col = Color(i);
            if (j < 3)
            {
                c[p].num = 0;
            }
            else
            {
                c[p].num = j - 1;
            }
        }
    }

    // draw deck initialize
    srand(time(NULL));

    for (int i = 0; i < 50; ++i)
    { // Shuffle playing cards
        int r1 = (double)rand() / (RAND_MAX + 1) * 72;
        int r2 = (double)rand() / (RAND_MAX + 1) * 72;

        while (r1 == r2)
        {
            r1 = (double)rand() / (RAND_MAX + 1) * 72;
            r2 = (double)rand() / (RAND_MAX + 1) * 72;
        }

        Card tmp = c[r1];
        c[r1] = c[r2];
        c[r2] = tmp;
    }

    for (int i = 0; i < 72; i++)
    { // Shuffled playing cards become DrawPile
        card_ptr tmp = new Card;
        tmp->col = c[i].col;
        tmp->num = c[i].num;
        DrawPile.Push(tmp);
    }

    // hand out 8 cards per player
    for (int i = 0; i < 8; i++)
    {
        P[0].deck.Add(DrawPile.Pop());
        P[1].deck.Add(DrawPile.Pop());
    }

    draw_num -= 16;
}

void OS::FieldStatus(Pile field[6])
{
    for (int i = 0; i < 6; i++)
    {
        switch (i)
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

        if (field[i].Peek() == NULL)
        {
            cout << "  | ";
        }
        else
        {
            int tmp = field[i].Peek()->num; // Print the number of top of current Color pile.
            if (tmp == 0)
            {
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
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void OS::Place()
{
    char dop; // dop: place the card on 'd'iscard field or 'p'layer's field
    int n;    // index of the card to be placed
    Pile *ObjectField;

    while (1)
    {
        cout << "Discard: d / Place: p: ";
        while (1)
        {
            cin >> dop;
            if (dop != 'd' && dop != 'p')
            { // wrong input
                cout << "Please re-enter." << endl;
            }
            else
            {
                break;
            }
        }

        cout << "Enter the index of the card to be placed: ";
        while (1)
        {
            cin >> n;
            if (n < 1 || n > 8)
            { // out of range
                cout << "Please re-enter." << endl;
            }
            else
            {
                break;
            }
        }

        card_ptr tmp = P[player].deck.Index(n - 1);
        P[player].deck.Remove(tmp);

        if (dop == 'd')
        {
            DiscardedColor = tmp->col;
            ObjectField = DiscardField;
        }
        else if (dop == 'p')
        {
            int co = int(tmp->col);
            if (P[player].field[co].Peek() && P[player].field[co].Peek()->num > tmp->num)
            { // Each new card that player place in player's field must have a higher value than the most recent card you have placed in it
                cout << "Please re-enter it from the beginning.\n"
                     << endl;
                continue;
            }
            else
            {
                DiscardedColor = nothing;
                ObjectField = P[player].field;
            }
        }

        ObjectField[int(tmp->col)].Push(tmp);
        break;
    }
}

void OS::Draw()
{
    int n, DiscardField_empty = 1; // n: for user selection / DiscardField_empty: emptiness of DiscardField

    for (int i = 0; i < 6; i++)
    {
        if (Color(i) == DiscardedColor)
        { // Check if DiscardField is empty
            continue;
        }
        if (DiscardField[i].Peek())
        {
            DiscardField_empty = 0;
            break;
        }
    }

    if (DiscardField_empty)
    {
        cout << "\nThere are no discarded cards to draw." << endl;
        cout << "New card is drawn automatically from Draw Pile." << endl;
        P[player].deck.Add(DrawPile.Pop());
        draw_num -= 1;
    }
    else
    {
        cout << "\nIf you want to darw new card from Discard Field, Enter 0," << endl;
        cout << "or, if you want to draw new card from Draw Pile, Enter 1:";

        while (1)
        {
            cin >> n;
            if (n == 0)
            { // Draw from Discard Field
                char c;
                Color co; // color of draw card

                cout << "Enter the first letter of the color you want.(both uppercase and lowercase letters):";
                while (1)
                {
                    int s = 1; // Control while loop
                    while (s)
                    {
                        cin >> c;

                        switch (c)
                        {
                        case 'Y':
                        case 'y':
                            co = yellow;
                            s = 0;
                            break;

                        case 'W':
                        case 'w':
                            s = 0;
                            co = white;
                            break;

                        case 'B':
                        case 'b':
                            s = 0;
                            co = blue;
                            break;

                        case 'G':
                        case 'g':
                            s = 0;
                            co = green;
                            break;

                        case 'R':
                        case 'r':
                            s = 0;
                            co = red;
                            break;

                        case 'P':
                        case 'p':
                            s = 0;
                            co = purple;
                            break;

                        default:
                            cout << "Please re-enter. Choose the correct color." << endl;
                        }
                    }

                    if (co == DiscardedColor)
                    { //방금 버린 카드는 가져오지 못한다.
                        cout << "You can't draw the same card that you have just discarded." << endl;
                        cout << "Please re-enter." << endl;
                    }
                    else if (!DiscardField[int(co)].Peek())
                    {
                        cout << "There are no cards of that color." << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                P[player].deck.Add(DiscardField[co].Pop());
                break;
            }

            else if (n == 1)
            { // draw from Draw Pile
                P[player].deck.Add(DrawPile.Pop());
                draw_num -= 1;
                break;
            }
            else
            {
                cout << "Please re-enter." << endl;
            }
        }
    }
    cout << "\nCureent Deck:" << endl;
    P[player].deck.DeckStatus();
    system("pause");
}
void OS::DrawNum()
{
    cout << "    " << draw_num << endl;
}

void OS::Turn()
{
    cout << "                     ==Player" << player + 1 << " Turn==\n"
         << endl;
    cout << "                            <P" << !player + 1 << ">" << endl;
    cout << "                        Score: " << P[!player].Score() << "\n"
         << endl;
    cout << "P" << !player + 1 << "'s Field     ";
    FieldStatus(P[!player].field);
    cout << "\n"
         << endl;

    for (int i = 0; i < 56; i++)
    {
        cout << "-";
    }
    cout << "   Draw\n"
         << endl;

    cout << "Discard Field  ";
    FieldStatus(DiscardField);

    DrawNum();

    for (int i = 0; i < 56; i++)
    {
        cout << "-";
    }

    cout << "\n"
         << endl;

    cout << "P" << player + 1 << "'s Field     ";
    FieldStatus(P[player].field);
    cout << "\n"
         << endl;

    cout << "                            <P" << player + 1 << ">" << endl;
    cout << "                         score: " << P[player].Score() << "\n"
         << endl;

    cout << "Your Current Deck:" << endl;
    P[player].deck.DeckStatus();

    Place();

    Draw();
    player = !player;
    system("cls");
}

int OS::GameEnd()
{
    if (DrawPile.isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void OS::WinnerMessage()
{
    if (P[0].Score() > P[1].Score())
    {
        cout << "Congraturation!!" << endl;
        cout << "The Winner is P1!!" << endl;
    }
    else if (P[0].Score() < P[1].Score())
    {
        cout << "Congraturation!!" << endl;
        cout << "The Winner is P2!!" << endl;
    }
    else
    {
        cout << "The game ended in a tie!" << endl;
    }
    system("cls");
}

#endif