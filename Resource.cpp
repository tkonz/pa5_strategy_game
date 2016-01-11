//
//  Resource.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Resource.h"
#include "Agent.h"
#include "Food.h"
#include "Advantage.h"

namespace Gaming
{
    const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;
    
    Resource::Resource(const Game &g, const Position &p, double __capacity)
    : Piece (g, p), __capacity(__capacity)
    {
        
    }
    
    Resource::~Resource()
    {
        
    }
    
    void Resource::age()
    {
        this->__capacity /= RESOURCE_SPOIL_FACTOR;
    }
    
    ActionType Resource::takeTurn(const Surroundings &s) const
    {
        return STAY;
    }
    
    Piece& Resource::operator*(Piece &other)
    {
        return other.interact(this);
    }
    
    Piece& Resource::interact(Agent *a)
    {
        Advantage *ad = dynamic_cast<Advantage*>(this);
        Food *food = dynamic_cast<Food*>(this);
        if (food)
        {
            a->addEnergy(food->getCapacity());
            food->finish();
        }
        else if (ad)
        {
            a->addEnergy(ad->getCapacity() * Advantage::ADVANTAGE_MULT_FACTOR);
            ad->finish();
        }
        return *this;
    }
    
    Piece& Resource::interact(Resource *r)
    {
        return *this;
    }
    
    
}