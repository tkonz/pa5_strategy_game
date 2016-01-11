//
// Created by Ivo Georgiev on 12/8/15.
//

#ifndef PA5GAME_STRATEGY_H
#define PA5GAME_STRATEGY_H

#include "Gaming.h"

namespace Gaming {
    
    class Strategy {
    public:
        //const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;
        Strategy() {}
        virtual ~Strategy() {};
        virtual ActionType operator()(const Surroundings &s) const = 0;
    };
    
}


#endif //PA5GAME_STRATEGY_H
