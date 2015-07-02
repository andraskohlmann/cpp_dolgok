#include "piece.h"

//using namespace chesspiece;
using namespace std;

vector<Position*>*
moveRook (const Position& pos, bool team1)
{
    vector<Position*> *vec = new vector<Position*>;

    for (int i = pos.i, j = 0; j < 8; ++j)
        if ( j != pos.j)
        {
            Position *p = new Position (i,j);
            vec->push_back(p);
        }

    for (int j = pos.j, i = 0; i < 8; ++i)
        if ( i != pos.i )
        {
            Position *p = new Position (i,j);
            vec->push_back(p);
        }

    return vec;
}

vector<Position*>*
moveBishop (const Position& pos, bool team1)
{
    vector<Position*> *vec = new vector<Position*>;

    return vec;
}

vector<Position*>*
moveKnight (const Position& pos, bool team1)
{
    vector<Position*> *vec = new vector<Position*>;

    return vec;
}

vector<Position*>*
moveKing (const Position& pos, bool team1)
{
    vector<Position*> *vec = new vector<Position*>;

    return vec;
}

vector<Position*>*
moveQueen (const Position& pos, bool team1)
{
    vector<Position*> *vec = new vector<Position*>;

    return vec;
}

vector<Position*>*
movePawn (const Position& pos, bool team1)
{
    vector<Position*> *vec = new vector<Position*>;
    Position *p;
    int i,j;

    if ( pos.j == 1 )
    {
        for (i = pos.i, j = pos.j; j < pos.j + 2; ++j)
        {
            p = new Position (i,j);
            vec->push_back(p);
        }

        if ( i > 0 )
        {
            p = new Position (i-1,j+1);
        }
    }
    else if ( pos.j == 6 )
    {
        for (i = pos.i, j = pos.j; j < pos.j - 2; --j)
        {
            Position *p = new Position (i,j);
            vec->push_back(p);
        }
    }
    else
    {


    }

    return vec;
}
