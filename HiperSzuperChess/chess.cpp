#include <cstdlib>
#include "chess.h"

movePiece miscLayout []= {
    moveRook,
    moveKnight,
    moveBishop,
    moveKing,
    moveQueen,
    moveBishop,
    moveKnight,
    moveRook
};

Field* Board::rowOfEmtpy (void) {
    Field* ret = new Field[8];
return ret;
}

Field* Board::rowOfMisc (bool team1) {
    Field* ret = (Field*) malloc ( 8 * sizeof (Field));

    if (ret == 0)
        throw std::bad_alloc ();

    for (int i = 0; i < 8; ++i)
    {
        ret[i] = new Piece (miscLayout[i],team1);
    }

return ret;
}

Field* Board::rowOfPawns (bool team1) {
    Field* ret = (Field*) malloc ( 8 * sizeof (Field));

    if (ret == 0)
        throw std::bad_alloc ();

    for (int i = 0; i < 8; ++i)
    {
        ret[i] = new Piece (movePawn,team1);
    }

return ret;
}

