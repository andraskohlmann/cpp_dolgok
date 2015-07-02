#ifndef PIECE_H_
#define PIECE_H_

#include <vector>
#include <iostream>

//namespace chesspiece {

class pieceException : public std::exception {
    virtual const char *what () const throw () {
            return "No piece initializer function!";
    }
};

struct Position {
    unsigned i,j;

    Position (unsigned _i, unsigned _j) : i(_i), j(_j) {}

    friend std::ostream& operator<< (std::ostream &os, const Position& p) {
        return os << "i: " << p.i << " j: " << p.j;
    }

};

typedef std::vector<Position*>* (*movePiece) (const Position&, bool);

class Piece {
bool team1;
public:
    movePiece availableMoves;
    Piece (movePiece aM_, bool team1_) : availableMoves (aM_), team1(team1_) {
            if (aM_ == 0)
                throw pieceException ();
    };

    bool getTeam () { return team1; }
};

std::vector<Position*>* moveRook    (const Position& pos, bool team1);
std::vector<Position*>* moveBishop  (const Position& pos, bool team1);
std::vector<Position*>* moveKnight  (const Position& pos, bool team1);
std::vector<Position*>* moveKing    (const Position& pos, bool team1);
std::vector<Position*>* moveQueen   (const Position& pos, bool team1);
std::vector<Position*>* movePawn    (const Position& pos, bool team1);

//}

#endif // PIECE_H_

