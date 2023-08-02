#include "chess_piece.h"
#include <ostream>
#include <string>

std::string to_string(Chess_piece_type type) {
    switch (type) {
        case pawn:
            return "p";
        case knight:
            return "k";
        case bishop:
            return "b";
        case rook:
            return "r";
        case queen:
            return "q";
        case king:
            return "K";
    }
}

bool Chess_piece::is_white() const {
    return this->_is_white;
}

Chess_piece_type Chess_piece::get_type() {
    return this->_type;
}

Chess_piece::Chess_piece(bool is_white, Chess_piece_type type) {
    this->_is_white = is_white;
    this->_type = type;
}


Chess_piece::Chess_piece() {
    this->_type = none;
}

std::ostream &operator<<(std::ostream &os, Chess_piece &chess_piece) {
    if (chess_piece.get_type() != none) {
        os << "(" << (chess_piece.is_white() ? "w" : "b") << "," << to_string(chess_piece.get_type()) << ")";
    } else {
        os << "     ";
    }
    return os;
}
