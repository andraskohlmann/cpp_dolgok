#ifndef PIECE_H_
#define PIECE_H_
#include <vector>
#include <iostream>
//namespace chesspiece {

class pieceException : public std::exception {
    virtual const char *what () const throw () {
        return "Invalid initializer function!";
    }
};

struct Position {
    int i,j;

    Position (int _i, int _j) : i(_i), j(_j) {}

    friend std::ostream& operator<< (std::ostream &os, const Position& p) {
        return os << "i: " << p.i << " j: " << p.j;
    }
};

typedef std::vector<Position*>* (*movePiece) (const Position&, ...);

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

std::vector<Position*>* moveRook    (const Position& pos, ...);
std::vector<Position*>* moveBishop  (const Position& pos, ...);
std::vector<Position*>* moveKnight  (const Position& pos, ...);
std::vector<Position*>* moveKing    (const Position& pos, ...);
std::vector<Position*>* moveQueen   (const Position& pos, ...);
std::vector<Position*>* movePawn    (const Position& pos, ...);
//}
#endif // PIECE_H_
