//
//  Advantage.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Advantage.h"

namespace Gaming
{
    const char Advantage::ADVANTAGE_ID = 'D';
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;
    
    Advantage::Advantage(const Game &g, const Position &p, double capacity)
    : Resource(g, p, capacity)
    {
        
    }
    
    Advantage::~Advantage()
    {
    }
    
    double Advantage::getCapacity() const
    {
        return this->__capacity * ADVANTAGE_MULT_FACTOR;
    }
}