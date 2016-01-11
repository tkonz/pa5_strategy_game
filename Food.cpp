//
//  Food.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Food.h"

namespace Gaming
{
    const char Food::FOOD_ID = 'F';
    Food::Food(const Game &g, const Position &p, double capacity)
    : Resource (g, p, capacity)
    {
    }
    
    Food::~Food()
    {
    }
}