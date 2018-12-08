//
//  RewardDeck.cpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839)(7895717). All rights reserved.
//

#include "rewarddeck.hpp"
RewardDeck* RewardDeck::myRDeck = nullptr;

RewardDeck& RewardDeck::make_CardDeck(){
    if(myRDeck == nullptr){
        myRDeck = new RewardDeck();
        for (int i : rewardList)  {
            myRDeck->deck.push_back(new Reward(i));
        }
        myRDeck->shuffle();
        return *myRDeck;
    }
    else{
        return *myRDeck;
    }
}
