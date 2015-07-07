#include <cstdio>
#include "chess.h"

int
main (void)
{
    Board b;
    Position p(0,0);
    Piece* pi;

    std::vector <Position*> *vec;
    std::vector <Position*>::const_iterator it;

    for (int i = 0; i < 8; ++i)
    {
        for ( int j = 0; j < 8; ++j)
        {
            p.i = i;
            p.j = j;

            std::cout << "At position " << p << "\n";

            pi = b.getPiece (p.i,p.j);

            if (pi)
            {
                vec = pi->availableMoves(p,true);
                std::cout << "Piece acquired!\n";
            }
            else
            {
                std::cout << "Empty field\n";
                continue;
            }

            for (it = (*vec).begin(); it != (*vec).end(); it++)
            {
                std::cout << *(*it) << "\n";
            }
        }
    }
    delete vec;

    printf ("Have piece %d\n",b.getPiece(1,0) == 0 ? 0x0 : 0x1);
}
