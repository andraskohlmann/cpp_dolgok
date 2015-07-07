#include "piece.h"
#include <cstdarg>

//using namespace chesspiece;
using namespace std;

inline bool
onBoard (int i, int j)
{
    return i >= 0 && i <= 7 && j >=0 && j <= 7;
}

vector<Position*>*
moveRook (const Position& pos, ...)
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
moveBishop (const Position& pos, ...)
{
    vector<Position*> *vec = new vector<Position*>;
    int i,j;

    /* Growing pattern */
    for (i = 1 ; pos.i + i < 8; ++i)
    {
        j = pos.j + i;
        if ( onBoard (pos.i + i,j))
            vec->push_back (new Position (pos.i + i,j));

        j = pos.j - i;
        if ( onBoard (i,j))
            vec->push_back (new Position (pos.i + i,j));
    }

    /* Diminishing pattern */
    for (i = 1; pos.i - i >= 0; ++i)
    {
        j = pos.j + i;
        if ( onBoard (pos.i - i,j))
            vec->push_back (new Position (pos.i - i,j));

        j = pos.j - i;
        if ( onBoard (i,j))
            vec->push_back (new Position (pos.i - i,j));
    }

    return vec;
}

static void
L (int i_, int j_, const Position& origin, vector<Position*>& vec)
{
    int direction;
    Position* p;
    int i,j;

    if (i_ - origin.i) /* If adjacent via i */
    {
        direction = i_ - origin.i;

        /* Long L */
        i = origin.i + 2*direction;
        j = origin.j + direction;

        if ( onBoard (i,j) )
        {
            p = new Position (i,j);
            vec.push_back (p);
        }

        /* Short L */
        j = origin.j + 2*direction;
        i = origin.i + direction;

        if ( onBoard (i,j) )
        {
            p = new Position (i,j);
            vec.push_back (p);
        }
    }
    else /* Adjacent via j */
    {
        direction = origin.j - j_;

        /* Short L */
        i = origin.i + 2*direction;
        j = origin.j - direction;;

        if ( onBoard (i,j) )
        {
            p = new Position (i,j);
            vec.push_back (p);
        }

        /* Long L */
        i = origin.i + direction;
        j = origin.j - 2*direction;

        if ( onBoard (i,j) )
        {
            p = new Position (i,j);
            vec.push_back (p);
        }
    }
}

vector<Position*>*
moveKnight (const Position& pos, ...)
{
    vector<Position*> *vec = new vector<Position*>;

    L (pos.i+1,pos.j,pos,*vec);
    L (pos.i-1,pos.j,pos,*vec);
    L (pos.i,pos.j+1,pos,*vec);
    L (pos.i,pos.j-1,pos,*vec);

    return vec;
}

vector<Position*>*
moveKing (const Position& pos, ...)
{
    vector<Position*> *vec = new vector<Position*>;

    for ( int i = pos.i-1 ; i <= pos.i+1; ++i)
    {
        for ( int j = pos.j-1; j <= pos.j + 1 ; ++j)
        {
            if ( onBoard (i,j) )
            {
                if ( i == pos.i && j == pos.j)
                    continue;
                else {
                    Position *p = new Position (i,j);
                    vec->push_back (p);
                }
            }
        }
    }
    return vec;
}

vector<Position*>*
moveQueen (const Position& pos, ...)
{
    vector<Position*> *tmp   = new vector<Position*>;
    vector<Position*> *vec   = new vector<Position*>;

    vec = moveRook   (pos);
    tmp = moveBishop (pos);

    vec->insert ( vec->end(), tmp->begin(), tmp->end() );

    return vec;
}

vector<Position*>*
movePawn (const Position& pos, ...)
{
    vector<Position*> *vec = new vector<Position*>;
    Position *p;
    int i,j;

    va_list vl;
    va_start (vl,pos);
    bool team1 = bool(va_arg (vl,int));
    va_end (vl);

    switch (team1)
    {
        case true:
            if ( pos.i == 1 )
            {
                    for ( j = pos.j-1; j <= pos.j+1; ++j)
                    {
                        if ( j >= 0 && j < 8 )
                        {
                            p = new Position (pos.i + 1,j);
                            vec->push_back (p);
                        }
                    }

                    p = new Position (pos.i + 2, pos.j);
                    vec->push_back (p);
            }
            else
            {
                if ( pos.i < 7 )
                {
                    for ( j = pos.j-1; j <= pos.j+1; ++j)
                    {
                        if ( j >= 0 && j < 8 )
                        {
                            p = new Position (pos.i + 1,j);
                            vec->push_back (p);
                        }
                    }
                }
            }
        return vec;
        case false:
            if ( pos.i == 6 )
            {
                    for ( j = pos.j-1; j <= pos.j+1; ++j)
                    {
                        if ( j >= 0 && j < 8 )
                        {
                            p = new Position (pos.i - 1,j);
                            vec->push_back (p);
                        }
                    }

                    p = new Position (pos.i - 2, pos.j);
                    vec->push_back (p);
            }
            else
            {
                if ( pos.i > 0 )
                {
                    for ( j = pos.j-1; j <= pos.j+1; ++j)
                    {
                        if ( j >= 0 && j < 8 )
                        {
                            p = new Position (pos.i - 1,j);
                            vec->push_back (p);
                        }
                    }
                }
            }
        return vec;
        default:
        return 0;
    }
}
