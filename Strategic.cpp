//
//  Strategic.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Strategic.h"
#include "Strategy.h"

namespace Gaming
{
    const char Strategic::STRATEGIC_ID = 'T';
    Strategic::Strategic(const Game &g, const Position &p, double energy, Strategy *s)
    : Agent(g, p, energy)
    {
        __strategy = s;
        
    }
    
    Strategic::~Strategic()
    {
        
    }
    
    ActionType Strategic::takeTurn(const Surroundings &s) const
    {
        ActionType ac = STAY;
        if (dynamic_cast <AggressiveAgentStrategy*> (__strategy))
        {
            ac = AggressiveAgentStrategy(this->__energy)(s);
        }
        else
            ac = DefaultAgentStrategy()(s);
        return ac;
    }
    
}