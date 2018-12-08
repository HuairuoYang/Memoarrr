//
//  CardDeck.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "carddeck.hpp"
CardDeck* CardDeck::myCDeck = nullptr;
bool CardDeck::roundOverShuffle = false;

CardDeck& CardDeck::make_CardDeck(){
    if(myCDeck == nullptr){
        myCDeck = new CardDeck();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                myCDeck->deck.push_back(new Card(FaceAnimal(i), FaceBackground(j)));
            }
        }
        myCDeck->shuffle();
        int l=0,n=0;
        for(auto k : myCDeck->deck){
            k->setLetter((Letter)l);
            k->setNumber((Number)n++);
            if(n==5){
                n = 0;
                l++;
            }
        }
        if(myCDeck->deck.empty()){
            roundOverShuffle = true;
            myCDeck->make_CardDeck();
            roundOverShuffle = false;
        }
        return *myCDeck;
    }
    else if(roundOverShuffle == true){
        myCDeck->shuffle();
        int l=0,n=0;
        for(auto k : myCDeck->deck){
            k->setLetter((Letter)l);
            k->setNumber((Number)n++);
            if(n==5){
                n = 0;
                l++;
            }
        }
        if(myCDeck->deck.empty()){
            roundOverShuffle = true;
            myCDeck->make_CardDeck();
            roundOverShuffle = false;
        }
        return *myCDeck;
    }
    else{
        if(myCDeck->deck.empty()){
            roundOverShuffle = true;
            myCDeck->make_CardDeck();
            roundOverShuffle = false;
        }
        return *myCDeck;
    }
}
