//
//  CardDeck.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "CardDeck.hpp"
CardDeck* CardDeck::myCDeck = nullptr;

CardDeck& CardDeck::make_CardDeck(){
    std::cout<<"enter make_CardDeck"<<std::endl;
    if(myCDeck == nullptr){
        std::cout<<"new deck"<<std::endl;
        myCDeck = new CardDeck();
        for (int i = 0; i < 5; i++) {
             std::cout<<"push row"<<std::endl;
            for (int j = 0; j < 5; j++) {
                myCDeck->deck.push_back(new Card(FaceAnimal(i), FaceBackground(j)));
            }
        }
        myCDeck->shuffle();
        return *myCDeck;
    }
    else{
         std::cout<<"find prev deck"<<std::endl;
        return *myCDeck;
    }
}
