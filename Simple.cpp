//
//  Simple.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Simple.h"

namespace Gaming
{
    const char Simple::SIMPLE_ID = 'S';
    
    Simple::Simple(const Game &g, const Position &p, double energy)
    : Agent (g, p, energy)
    {
        
    }
    
    Simple::~Simple()
    {
        
    }
    
    ActionType Simple::takeTurn(const Surroundings &s) const
    {
        
        ActionType ac;
        for (int i = 0; i < 9; i++)
        {
            int n = static_cast<int>(s.array[i]);
            if (n == 2) // FOOD
            {
                
                if (i == 0)
                {
                    return NW;
                }
                else if (i == 1)
                {
                    return N;
                }
                else if (i == 2)
                {
                    return NE;
                }
                else if (i == 3)
                {
                    return W;
                }
                else if (i == 5)
                {
                    int x5 = getPosition().x;
                    int x6 = getPosition().y;
                    return E;
                }
                else if (i == 6)
                {
                    return SW;
                }
                else if (i == 7)
                {
                    return S;
                }
                else if (i == 8)
                {
                    return SE;
                }
            }
            else if (n == 3) // ADVANTAGE
            {
                if (i == 0)
                {
                    return NW;
                }
                else if (i == 1)
                {
                    return N;
                }
                else if (i == 2)
                {
                    return NE;
                }
                else if (i == 3)
                {
                    return W;
                }
                else if (i == 5)
                {
                    return E;
                }
                else if (i == 6)
                {
                    return SW;
                }
                else if (i == 7)
                {
                    return S;
                }
                else if (i == 8)
                {
                    return SE;
                }
            }
            else if (n == 6) // EMPTY
            {
                if (i == 0)
                {
                    return NW;
                }
                else if (i == 1)
                {
                    return N;
                }
                else if (i == 2)
                {
                    return NE;
                }
                else if (i == 3)
                {
                    return W;
                }
                else if (i == 5)
                {
                    if (getPosition().x == 0 && getPosition().y == __game.getHeight()-1)
                        return S;
                    else if (getPosition().x == 0 && getPosition().y == __game.getHeight()-2)
                        return SW;
                    else if (getPosition().y == __game.getHeight()-1 && getPosition().x == __game.getWidth()-1)
                        return N;
                    else if (getPosition().y == __game.getHeight()-1 && getPosition().x == __game.getWidth()-2)
                        return NW;
                    else
                        return E;
                }
                else if (i == 6)
                {
                    return SW;
                }
                else if (i == 7)
                {
                    return S;
                }
                else if (i == 8)
                {
                    return SE;
                }
            }
            else
                ac = STAY;
            
        }
        return STAY;
    }
}
