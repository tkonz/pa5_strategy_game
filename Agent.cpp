//
//  Agent.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Agent.h"
#include "Resource.h"
#include "Advantage.h"
#include "Food.h"

namespace Gaming
{
    const double Agent::AGENT_FATIGUE_RATE = 0.3;
    
    Agent::Agent(const Game &g, const Position &p, double energy)
    : Piece (g, p), __energy(energy)
    {
    }
    
    Agent::~Agent()
    {
        //std::cout << "Destroying Derived class Agent\n";
        std::cout << "Destroying Derived class Agent\n";
    }
    
    void Agent::age()
    {
        this->__energy -= AGENT_FATIGUE_RATE;
    }
    
    Piece& Agent::operator*(Piece &other)
    {
        return other.interact(this);
    }
    
    Piece & Agent::interact(Agent *a)
    {
        if (this->__energy == a->__energy)
        {
            this->finish();
            a->finish();
            return *this;
            
        }
        else
        {
            if (this->__energy > a->__energy)
            {
                __energy = __energy - (a->__energy);
                a->finish();
            }
            else
            {
                a->__energy = a->__energy - __energy;
                this->finish();
            }
            
        }
        return *this;
        
    }
    
    Piece& Agent::interact(Resource *r)
    {
        Food *food = dynamic_cast<Food*>(r);
        Advantage *ad = dynamic_cast<Advantage*>(r);
        if (food)
        {
            this->__energy = __energy + food->getCapacity();
            r->isViable();
        }
        else if (ad)
        {
            this->__energy = __energy + (ad->getCapacity() * Advantage::ADVANTAGE_MULT_FACTOR);
            r->isViable();
        }
        return *this;
    }
    
}