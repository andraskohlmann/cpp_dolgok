#include <cstdio>
#include "chess.h"

int
main (void)
{
    Board b;
    Position p(5,6);

    std::vector <Position*> *vec = moveRook (p,true);

    std::vector <Position*>::const_iterator it;

    for (it = (*vec).begin(); it != (*vec).end(); it++)
    {
        std::cout << *(*it) << "\n";
    }

    delete vec;

    printf ("Hello %d\n",b.getPiece(1,0) == 0 ? 0x0 : 0x1);
}
