#ifndef HANDIN5_CHESS_PIECE_H
#define HANDIN5_CHESS_PIECE_H

#include <ostream>

enum Chess_piece_type { pawn, knight, bishop, rook, queen, king, none };

class Chess_piece {
private:
    bool _is_white;
    Chess_piece_type _type;
public:
    Chess_piece();
    Chess_piece(bool is_white, Chess_piece_type type);
    bool is_white() const;
    Chess_piece_type get_type();
    friend std::ostream& operator<<(std::ostream& os, Chess_piece& chess_piece);
};


#endif //HANDIN5_CHESS_PIECE_H