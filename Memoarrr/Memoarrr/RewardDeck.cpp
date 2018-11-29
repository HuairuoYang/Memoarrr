//
//  RewardDeck.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "RewardDeck.hpp"
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
