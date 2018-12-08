//
//  RewardDeck.hpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
//

#ifndef RewardDeck_hpp
#define RewardDeck_hpp

#include <stdio.h>
#include "deck.hpp"
#include "reward.hpp"

class RewardDeck : public Deck<Reward>{
    static RewardDeck* myRDeck;
    RewardDeck() = default;
    RewardDeck(const RewardDeck&) = delete;
    RewardDeck& operator= ( const RewardDeck & ) = delete;
public:
    static RewardDeck& make_CardDeck();
};

#endif /* RewardDeck_hpp */
