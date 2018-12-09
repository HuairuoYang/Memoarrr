//
//  CardDeck.cpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
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
            k->setIndex((Letter)l,(Number)n++);
            Letter a=k->getLetter();
            Number z=k->getNumber();
            if (a==Letter::B&&z==Number::three){
                k->bottomAvailable=false;
            }
            if (a==Letter::C&&z==Number::two){
                k->rightAvailable=false;
            }
            if (a==Letter::C&&z==Number::four){
                k->leftAvailable=false;
            }
            if (a==Letter::D&&z==Number::three){
                k->topAvailable=false;
            }
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
            k->setIndex((Letter)l,(Number)n++);
            Letter a=k->getLetter();
            Number z=k->getNumber();
            if (a==Letter::B&&z==Number::three){
                k->bottomAvailable=false;
            }
            if (a==Letter::C&&z==Number::two){
                k->rightAvailable=false;
            }
            if (a==Letter::B&&z==Number::four){
                k->leftAvailable=false;
            }
            if (a==Letter::D&&z==Number::three){
                k->topAvailable=false;
            }
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
