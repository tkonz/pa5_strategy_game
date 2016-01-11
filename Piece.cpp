//
//  Piece.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Piece.h"

namespace Gaming {
    unsigned Piece::__idGen = 0;
    Piece::Piece(const Game &g, const Position &p) : __game(g), __position(p), __id(++__idGen)
    {
        __finished = false;
        __turned = false;
    }
    
    Piece::~Piece()
    {
            std::cout << "Destroying Base for Piece\n";
    }
    
    std::ostream &operator<<(std::ostream &os, const Piece &piece)
    {
        if (piece.getType() == SIMPLE)
        {
            os << "S" << piece.__id;
        }
        else if (piece.getType() == STRATEGIC)
        {
            os << "T" << piece.__id;
        }
        else if (piece.getType() == FOOD)
        {
            os << "F" << piece.__id;
        }
        else if (piece.getType() == ADVANTAGE)
        {
            os << "D" << piece.__id;
        }
        return os;
    }
}