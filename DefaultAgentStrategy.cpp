
//
//  DefaultAgentStrategy.cpp
//  PA5
//
//  Created by Tisha Konz on 1/10/16.
//  Copyright (c) 2016 Tisha Konz. All rights reserved.
//

#include "DefaultAgentStrategy.h"


namespace Gaming
{
    
    DefaultAgentStrategy::DefaultAgentStrategy()
    {
    
    }
    
    DefaultAgentStrategy::~DefaultAgentStrategy()
    {
    
    }
    
    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const
    {
        ActionType ac = STAY;
        
        for (int i = 0; i < 9; i++)
        {
            int n = static_cast<int>(s.array[i]);
            if (n == 3) // ADVANTAGE
            {
                ac = static_cast<ActionType>(i);
                if (ac == 2)
                    return NE;
                else if (ac == 0)
                    return NW;
                else if (ac == 1)
                    return N;
                else if (ac == 4)
                    return STAY;
                else if (ac == 8)
                    return NE;
                else if (ac == 3)
                    return W;
                else if (ac == 6)
                    return SW;
                else if (ac == 7)
                    return S;
                else if (ac == 5)
                    return E;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            int n = static_cast<int>(s.array[i]);
            if (n == 2) // FOOD
            {
                ac = static_cast<ActionType>(i);
                if (ac == 2)
                    return NW;
                else if (ac == 0)
                    return N;
                else if (ac == 1)
                    return NE;
                else if (ac == 4)
                    return W;
                else if (ac == 8)
                    return STAY;
                else if (ac == 3)
                    return E;
                else if (ac == 6)
                    return SW;
                else if (ac == 7)
                    return S;
                else if (ac == 5)
                    return SE;
                
            }
        }
        for (int i = 0; i < 9; i++)
        {
            int n = static_cast<int>(s.array[i]);
            if (n == 6) // EMPTY
            {
                ac = static_cast<ActionType>(i);
                if (ac == 2)
                    return NE;
                else if (ac == 0)
                    return NW;
                else if (ac == 1)
                    return N;
                else if (ac == 4)
                    return STAY;
                else if (ac == 8)
                    return NE;
                else if (ac == 3)
                    return W;
                else if (ac == 6)
                    return SW;
                else if (ac == 7)
                    return S;
                else if (ac == 5)
                    return E;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            int n = static_cast<int>(s.array[i]);
            if (n == 0) // AGENT
            {
                ac = static_cast<ActionType>(i);
                if (ac == 2)
                    return NE;
                else if (ac == 0)
                    return NW;
                else if (ac == 1)
                    return N;
                else if (ac == 4)
                    return STAY;
                else if (ac == 8)
                    return NE;
                else if (ac == 3)
                    return W;
                else if (ac == 6)
                    return SW;
                else if (ac == 7)
                    return S;
                else if (ac == 5)
                    return E;
            }
        }
        return ac;
    }
}