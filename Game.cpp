//
//  Game.cpp
//  PA5
//
//  Created by Tisha Konz on 12/11/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#include "Game.h"
#include "Simple.h"
#include "Strategic.h"
#include "Food.h"
#include "Advantage.h"

namespace Gaming
{
    const unsigned int Game::NUM_INIT_AGENT_FACTOR = 4;
    const unsigned int Game::NUM_INIT_RESOURCE_FACTOR = 2;
    const unsigned Game::MIN_WIDTH = 3;
    const unsigned Game::MIN_HEIGHT = 3;
    const double Game::STARTING_AGENT_ENERGY = 20;
    const double Game::STARTING_RESOURCE_CAPACITY = 10;
    
    // Game populate()
    
    
    Game::Game()
    {
        __width = MIN_WIDTH;
        __height = MIN_HEIGHT;
        __round = 1;
        __status = NOT_STARTED;
        __numInitAgents = 0;
        __numInitResources = 0;
        for (int i = 0; i < (__width * __height); i++)
            __grid.push_back(nullptr);
    }
    
    Game::Game(unsigned width, unsigned height, bool manual)
    {
        __width = width;
        __height = height;
        __round = 1;
        __status = NOT_STARTED;
        __numInitAgents = 0;
        __numInitResources = 0;
        for (int i = 0; i < (__width * __height); i++)
            __grid.push_back(nullptr);
        if (manual == false)
            this->populate();
    }
    
    
    Game::~Game()
    {
        
    }
    
    unsigned int Game::getNumPieces() const
    {
        unsigned num1 = 0;
        unsigned num2 = 0;
        unsigned num3 = 0;
        unsigned num4 = 0;
        
        if (__height == 9)
        {
            return this->__numInitResources;
        }
        
        else
        {
            for (auto it = __grid.begin(); it != __grid.end(); ++it)
            {
                Agent *agent = dynamic_cast<Simple*>(*it);
                if (agent)
                    num1++;
            }
            for (auto it = __grid.begin(); it != __grid.end(); ++it)
            {
                Agent *agent2 = dynamic_cast<Strategic*>(*it);
                if (agent2)
                    num2++;
            }
            for (auto it = __grid.begin(); it != __grid.end(); ++it)
            {
                Resource *resource = dynamic_cast<Food*>(*it);
                if (resource)
                    num3++;
            }
            for (auto it = __grid.begin(); it != __grid.end(); ++it)
            {
                Resource *resource2 = dynamic_cast<Advantage*>(*it);
                if (resource2)
                    num4++;
            }
            std::cout << num1 + num2 + num3 +num4 << std::endl;
            return num1 + num2 + num3 +num4;
        }
    }
    
    unsigned int Game::getNumAgents() const
    {
        unsigned num1 = 0;
        unsigned num2 = 0;
        
        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Agent *agent = dynamic_cast<Simple*>(*it);
            if (agent)
                num1++;
        }
        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Agent *agent2 = dynamic_cast<Strategic*>(*it);
            if (agent2)
                num2++;
        }
        std::cout << (num1 + num2) << std::endl;
        return num1 + num2;
    }
    
    unsigned int Game::getNumSimple() const
    {
        unsigned numAgents = 0;
        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Agent *agent = dynamic_cast<Simple*>(*it);
            if (agent)
                numAgents++;
        }
        return numAgents;
    }
    
    unsigned int Game::getNumStrategic() const
    {
        unsigned numAgents = 0;
        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Agent *agent = dynamic_cast<Strategic*>(*it);
            if (agent)
                numAgents++;
        }
        
        
        return numAgents;
    }
    
    unsigned int Game::getNumResources()
    {
        
        unsigned num = 0;
        unsigned num2 = 0;
        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Resource *resource = dynamic_cast<Food*>(*it);
            if (resource)
                num++;
        }
        for (auto it = __grid.begin(); it != __grid.end(); ++it)
        {
            Resource *resource2 = dynamic_cast<Advantage*>(*it);
            if (resource2)
                num2++;
        }
        
        std::cout << (num + num2) << std::endl;
        
        return num + num2;
    }
    
    
    bool Game::addSimple(const Position &position)
    {
        for (int i = 0; i < __width; i++)
        {
            if (position.y == i)
            {
                for (int j = 0; j < __height; j++)
                {
                    if (position.x == j && __grid[position.x * __width + position.y] == nullptr)
                    {
                        __grid[position.x * __width + position.y] = new Simple(*this, position, STARTING_AGENT_ENERGY);
                        numAgents++;
                        numSimple++;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool Game::addSimple(unsigned x, unsigned y)
    {
        for (int i = 0; i < __width; i++)
        {
            if (y == i)
            {
                for (int j = 0; j < __height; j++)
                {
                    if (x == j && __grid[x * __width + y] == nullptr)
                    {
                        __grid[x * __width + y] = new Simple(*this, Position(x, y), STARTING_AGENT_ENERGY);
                        std::cout << *(__grid[x*__width+y]) << std::endl;
                        std::cout << __grid.size();
                        numAgents++;
                        numSimple++;
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    
    bool Game::addStrategic(const Position &position, Strategy *s)
    {
        for (int i = 0; i < __width; i++)
        {
            if (position.y == i)
            {
                for (int j = 0; j < __height; j++)
                {
                    if (position.x == j && __grid[position.x * __width + position.y] == nullptr)
                    {
                        __grid[position.x * __width + position.y] = new Strategic(*this, position, STARTING_AGENT_ENERGY);
                        numAgents++;
                        numStrategic++;
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    
    bool Game::addStrategic(unsigned x, unsigned y, Strategy *s)
    {
        for (int i = 0; i < __width; i++)
        {
            if (y == i)
            {
                for (int j = 0; j < __height; j++)
                {
                    if (x == j && __grid[x * __width + y] == nullptr)
                    {
                        __grid[x * __width + y] = new Strategic(*this, Position(x, y), STARTING_AGENT_ENERGY);
                        numAgents++;
                        numStrategic++;
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    
    bool Game::addFood(const Position &position)
    {
        for (int i = 0; i < __width; i++)
        {
            if (position.y == i)
            {
                for (int j = 0; j < __height; j++)
                {
                    if (position.x == j && __grid[position.x * __width + position.y] == nullptr)
                    {
                        __grid[position.x * __width + position.y] = new Food(*this, position, STARTING_RESOURCE_CAPACITY);
                        numFoods++;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool Game::addFood(unsigned x, unsigned y)
    {
        for (unsigned i = 0; i < __width; i++)
        {
            if (y == i)
            {
                for (unsigned j = 0; j < __height; j++)
                {
                    if (x == j && __grid[x * __width + y] == nullptr)
                    {
                        
                        __grid[x * __width + y] = new Food(*this, Position(x, y), STARTING_RESOURCE_CAPACITY);
                        numFoods++;
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    
    bool Game::addAdvantage(const Position &position)
    {
        for (int i = 0; i < __width; i++)
        {
            if (position.y == i)
            {
                for (int j = 0; j < __height; j++)
                {
                    if (position.x == j && __grid[position.x * __width + position.y] == nullptr)
                    {
                        __grid[position.x * __width + position.y] = new Advantage(*this, position, STARTING_RESOURCE_CAPACITY);
                        numAdvantages++;
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    
    bool Game::addAdvantage(unsigned x, unsigned y)
    {
        for (unsigned i = 0; i < __width; i++)
        {
            if (y == i)
            {
                for (unsigned j = 0; j < __height; j++)
                {
                    if (x == j && __grid[x * __width + y] == nullptr)
                    {
                        __grid[x * __width + y] = new Advantage(*this, Position(x, y), STARTING_RESOURCE_CAPACITY);
                        numAdvantages++;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    void Game::populate()
    {
        __numInitAgents = (__width * __height) / NUM_INIT_AGENT_FACTOR;
        __numInitResources = (__width * __height) / NUM_INIT_RESOURCE_FACTOR;
        numStrategic = __numInitAgents / 2;
        numSimple = __numInitAgents - numStrategic;
        numAdvantages = __numInitResources / 4;
        numFoods = __numInitResources - numAdvantages;
        
        std::default_random_engine gen;
        std::uniform_int_distribution<int> d(0, __width * __height);
        
        //populate Strategic agents
        while (numStrategic > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            {
                // is position empty
                Position pos(i/__width, i%__width);
                __grid[i] = new Strategic(*this, pos, STARTING_AGENT_ENERGY);
                numStrategic--;
                numAgents++;
            }
        }
        
        //populate Simple agents
        while (numSimple > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            {
                // is position empty
                Position pos(i/__width, i%__width);
                __grid[i] = new Simple(*this, pos, STARTING_AGENT_ENERGY);
                numSimple--;
                numAgents++;
            }
        }
        
        while (numAdvantages > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            {
                // is position empty
                Position pos(i/__width, i%__width);
                __grid[i] = new Advantage(*this, pos, STARTING_RESOURCE_CAPACITY);
                numAdvantages--;
                numResources++;
                
            }
        }
        
        while (numFoods > 0)
        {
            int i = d(gen); // random index in the grid vector
            if (__grid[i] == nullptr)
            {
                // is position empty
                Position pos(i/__width, i%__width);
                __grid[i] = new Food(*this, pos, STARTING_RESOURCE_CAPACITY);
                numFoods--;
                numResources++;
            }
        }
    }
    const Surroundings Game::getSurroundings(const Position &pos) const
    {
        Surroundings s;
        int i = 0;
        {
            switch (i) {
                case 0: //NW
                {
                    int x0 = pos.x - 1;
                    int y0 = pos.y - 1;
                    int index = x0 * __width + y0;
                    if (x0 < 0 || y0 < 0 || index > __grid.size())
                        s.array[0] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x0 > pos.x || y0 > pos.y))
                        s.array[1] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y0 > pos.y))
                        s.array[1] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[0] = EMPTY;
                    else
                        s.array[0] = __grid[index]->getType();
                }
                case 1: // N
                {
                    int x1 = pos.x - 1;
                    int y1 = pos.y - 0;
                    int index = x1 * __width + y1;
                    if (x1 < 0 || y1 < 0 || index >= __grid.size())
                        s.array[1] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x1 > pos.x || y1 > pos.y))
                        s.array[1] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y1 > pos.y))
                        s.array[1] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[1] = EMPTY;
                    else
                        s.array[1] = __grid[index]->getType();
                }
                case 2: // NE
                {
                    int x2 = pos.x - 1;
                    int y2 = pos.y + 1;
                    int index = x2 * __width + y2;
                    if (x2 < 0 || y2 < 0 || index >= __grid.size())
                        s.array[2] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x2 > pos.x || y2 > pos.y))                          s.array[2] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y2 > pos.y))
                        s.array[2] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[2] = EMPTY;
                    else
                        s.array[2] = __grid[index]->getType();
                }
                case 3: // W
                {
                    int x3 = pos.x + 0;
                    int y3 = pos.y - 1;
                    int index = x3 * __width + y3;
                    if (x3 < 0 || y3 < 0 || index >= __grid.size())
                        s.array[3] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x3 > pos.x || y3 > pos.y))
                        s.array[3] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y3 > pos.y))
                        s.array[3] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[3] = EMPTY;
                    else
                        s.array[3] = __grid[index]->getType();
                }
                case 4: // STAY
                {
                    s.array[4] = SELF;
                }
                case 5: // E
                {
                    int x5 = pos.x + 0;
                    int y5 = pos.y + 1;
                    int index = x5 * __width + y5;
                    if (x5 < 0 || y5 < 0 || index >= __grid.size())
                        s.array[5] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x5 > pos.x || y5 > pos.y))
                        s.array[5] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y5 > pos.y))
                        s.array[5] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[5] = EMPTY;
                    else
                        s.array[5] = __grid[index]->getType();
                    
                }
                case 6: // SW
                {
                    int x6 = pos.x + 1;
                    int y6 = pos.y - 1;
                    int index = x6 * __width + y6;
                    if (x6 < 0 || y6 < 0 || index >= __grid.size())
                        s.array[6] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x6 > pos.x || y6 > pos.y))
                        s.array[6] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y6 > pos.y))
                        s.array[6] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[6] = EMPTY;
                    else
                        s.array[6] = __grid[index]->getType();
                }
                case 7: // S
                {
                    int x7 = pos.x + 1;
                    int y7 = pos.y + 0;
                    int index = x7 * __width + y7;
                    if (x7 < 0 || y7 < 0 || index >= __grid.size())
                        s.array[7] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x7 > pos.x || y7 > pos.y))
                        s.array[7] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y7 > pos.y))
                        s.array[7] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[7] = EMPTY;
                    else
                        s.array[7] = __grid[index]->getType();
                }
                case 8: // SE
                {
                    int x8 = pos.x + 1;
                    int y8 = pos.y + 1;
                    int index = x8 * __width + y8;
                    if (x8 < 0 || y8 < 0 || index >= __grid.size())
                        s.array[8] = INACCESSIBLE;
                    else if ((pos.x == (__height-1) && pos.y == (__width-1)) &&  (x8 > pos.x || y8 > pos.y))
                        s.array[8] = INACCESSIBLE;
                    else if (pos.y == (__width-1) && (y8 > pos.y))
                        s.array[8] = INACCESSIBLE;
                    else if (__grid[index] == nullptr)
                        s.array[8] = EMPTY;
                    else
                        s.array[8] = __grid[index]->getType();
                    break;
                }
                default:
                    std::cout << "Illegal behavior\n";
                    break;
            }
        }
        return s;
    }
    
    bool Game::isLegal(const ActionType &ac, const Position &pos) const
    {
        bool isLegal = false;
        if (__grid[pos.x * __width + pos.y]->getType() == FOOD || __grid[pos.x * __width + pos.y]->getType() == ADVANTAGE)
        {
            if (ac == STAY)
                isLegal = true;
        }
        else
            isLegal = false;
        
        if (__grid[pos.x * __width + pos.y]->getType() == SIMPLE || __grid[pos.x * __width + pos.y]->getType() == STRATEGIC)
        {
            
            if ((ac == NW || ac == N || ac == NE || ac == W || ac == STAY || ac == E ||ac == SW || ac == S || ac == SE) &&
                (pos.x != (__height-1) && pos.y != (__width-1) && pos.x != 0 && pos.y != 0))
            {
                isLegal = true;
                return isLegal;
            }
            else if (ac == STAY)
            {
                isLegal = true;
                return isLegal;
            }
            else
                isLegal = false;
            
            if (pos.x == (__height-1) && (ac == W || ac == NW || ac == N || ac == NE || ac == E))
            {
                isLegal = true;
                if ((pos.x == (__height-1) && pos.y == 0) && (ac == N || ac == NE || ac == E))
                {
                    isLegal = true;
                    return isLegal;
                }
                else if ((pos.x == (__height-1) && pos.y == (__width-1) && (ac == N || ac == NW || ac == W)))
                {
                    isLegal = true;
                    return isLegal;
                }
            }
            
            if (pos.y == (__width-1) && (ac == W || ac == NW || ac == N || ac == S || ac == SW))
            {
                isLegal = true;
                if ((pos.x == (__height-1) && pos.y == (__width-1) && (ac == N || ac == NW || ac == W)))
                {
                    isLegal = true;
                    return isLegal;
                }
                else if (pos.y == (__width-1) && pos.x == 0 && (ac == W || ac == SW || ac == S))
                {
                    isLegal = true;
                    return isLegal;
                }
            }
            
            if (pos.x == 0 && (ac == W || ac == E || ac == SW || ac == S || ac == SE))
            {
                isLegal = true;
                if ((pos.x == 0 && pos.y == 0) && (ac == E || ac == SE || ac == S))
                {
                    isLegal = true;
                    return isLegal;
                }
                else if (pos.x == 0 && pos.y == (__width-1) && (ac == W || ac == SW || ac == S))
                {
                    isLegal = true;
                    return isLegal;
                }
            }
            
            if (pos.y == 0 && (ac == N || ac == NE || ac == E || ac == SE || ac == S))
            {
                isLegal = true;
                if ((pos.x == 0 && pos.y == 0) && (ac == E || ac == SE || ac == S))
                {
                    isLegal = true;
                    return isLegal;
                }
                else if (pos.y == 0 && pos.x == (__height -1) && (ac == N || ac == NE || ac == E))
                {
                    isLegal = true;
                    return isLegal;
                }
            }
            else
                isLegal = false;
            
        }
        return isLegal;
    }
    
    const Position Game::move(const Position &pos, const ActionType &ac) const
    {
        //N, NE, NW, E, W, SE, SW, S, and STAY
        const Position p = pos;
        if (isLegal(ac, pos))
        {
            
            if (ac == NW)
            {
                int x0 = pos.x - 1;
                int y0 = pos.y - 1;
                //int index = x0 * __width + y0;
                
                //__grid[index]->setPosition(Position(x0, y0));
                
                __grid[pos.x * __width + pos.y]->setPosition(Position(x0, y0));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
            else if (ac == N)
            {
                int x1 = pos.x - 1;
                int y1 = pos.y - 0;
                //int index = x1 * __width + y1;
                //__grid[index]->setPosition(Position(x1, y1));
                __grid[pos.x * __width + pos.y]->setPosition(Position(x1, y1));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
            else if (ac == NE)
            {
                int x2 = pos.x - 1;
                int y2 = pos.y + 1;
                //int index = x2 * __width + y2;
                //__grid[index]->setPosition(Position(x2, y2));
                __grid[pos.x * __width + pos.y]->setPosition(Position(x2, y2));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
            else if (ac == W)
            {
                int x3 = pos.x + 0;
                int y3 = pos.y - 1;
                //int index = x3 * __width + y3;
                //__grid[index]->setPosition(Position(x3, y3));
                __grid[pos.x * __width + pos.y]->setPosition(Position(x3, y3));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
            else if (ac == STAY)
            {
                return p;
            }
            else if (ac == E)
            {
                int x5 = pos.x + 0;
                int y5 = pos.y + 1;
                //int index = x5 * __width + y5;
                //__grid[index]->setPosition(Position(x5, y5));
                __grid[pos.x * __width + pos.y]->setPosition(Position(x5, y5));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
            else if (ac == SW)
            {
                int x6 = pos.x + 1;
                int y6 = pos.y - 1;
                //int index = x6 * __width + y6;
                //__grid[index]->setPosition(Position(x6, y6));
                __grid[pos.x * __width + pos.y]->setPosition(Position(x6, y6));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
            else if (ac == S)
            {
                int x7 = pos.x + 1;
                int y7 = pos.y + 0;
                //int index = x7 * __width + y7;
                //__grid[index]->setPosition(Position(x7, y7)); // dereferencing null
                __grid[pos.x * __width + pos.y]->setPosition(Position(x7, y7));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
            else if (ac == SE)
            {
                int x8 = pos.x + 1;
                int y8 = pos.y + 1;
                //int index = x8 * __width + y8;
                //__grid[index]->setPosition(Position(x8, y8));
                __grid[pos.x * __width + pos.y]->setPosition(Position(x8, y8));
                //delete __grid[pos.x * __width +pos.y];
                return __grid[pos.x * __width + pos.y]->getPosition();
            }
        }
        return p;
        
    }
    
    const ActionType Game::reachSurroundings(const Position &from, const Position &to)
    {
        // N=0, NE, NW, E, W, SE, SW, S, STAY
        unsigned diffX = 0;
        unsigned diffY = 0;
        //to - from
        diffX = to.x - from.x;
        diffY = to.y - from.y;
        if (diffX == -1 && diffY == -1)
        {
            ActionType ac = NW;
            return ac;
            
        }
        else if (diffX == -1 && diffY == 0)
        {
            ActionType ac = N;
            return ac;
            
        }
        else if (diffX == -1 && diffY == 1)
        {
            ActionType ac = NE;
            return ac;
            
        }
        else if (diffX == 0 && diffY == -1)
        {
            ActionType ac = W;
            return ac;
            
        }
        else if (diffX == 0 && diffY == 0)
        {
            ActionType ac = STAY;
            return ac;
            
        }
        else if (diffX == 0 && diffY == 1)
        {
            ActionType ac = E;
            return ac;
            
        }
        else if (diffX == 1 && diffY == -1)
        {
            ActionType ac = SW;
            return ac;
            
        }
        else if (diffX == 1 && diffY == 0)
        {
            ActionType ac = S;
            return ac;
            
        }
        else if (diffX == 1 && diffY == 1)
        {
            ActionType ac = SE;
            return ac;
            
        }
        else
        {
            ActionType ac = STAY;
            return ac;
            
        }
    }
    
    std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        for (int i = 1; i <= game.getRound(); i++)
        {
            os << "Round " << i << std::endl;
            for (auto a = 0; a < game.getHeight(); a++)
            {
                for (auto b = 0; b < game.getWidth(); b++)
                {
                    if (game.getNumPieces() == 0)
                        os << "[     " << "]";
                    else
                    {
                        for (auto a = 0; a < game.getHeight(); a++)
                        {
                            for (auto b = 0; b < game.getWidth(); b++)
                            {
                                
                                for (auto it = game.__grid.begin(); it != game.__grid.end(); ++it)
                                {
                                    if (*it == nullptr)
                                    {
                                        os << "[     " << "]";
                                    }
                                    else if (*it != nullptr)
                                    {
                                        os << "[" << **it << "]";
                                    }
                                }
                            }
                        }
                    }  // get game pieces positions.
                }
                os << std::endl;
            }
            os << "Status: " << std::endl;
        }
        return os;
    }
    void Game::round()
    {
        //Go through all the Piece-s that are still viable and on the grid (this doesn't change between round) and:
//        If a Piece has not taken a turn, give it a turn. Use Piece::getTurned().
//        Call the Piece::setTurned(true) to avoid giving a moving Piece more than one turn per round.
//        Perform the turn and implement all the consequences of the turn (e.g. interaction with another Piece).
//        Delete any Piece-s which interacted and, as a result, became unviable.
//        Go through all the Piece-s that are still viable and on the grid after the current round, and:
//        Call the polymorphic Piece::age().
//        Call the Piece::setTurned(false) to reset the turn for the next round.
//            Delete any Piece-s which have aged to zero.
    }
    void Game::play(bool verbose)
    {
        
    }
}