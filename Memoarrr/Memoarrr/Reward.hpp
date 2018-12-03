//
//  Reward.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Reward_hpp
#define Reward_hpp

#include <stdio.h>
#include "Utils.hpp"
#include <iostream>

class Reward{
    int numOfRubies=0;
    friend class RewardDeck;
    Reward(const Reward&) = delete;
    Reward& operator= ( const Reward & ) = delete;
    Reward(int ruby):numOfRubies{ruby}{};
 
public:
    friend std::ostream& operator<<(std::ostream& os,Reward & r) {
        return os << std::to_string(r.numOfRubies);
    }
};

#endif /* Reward_hpp */
