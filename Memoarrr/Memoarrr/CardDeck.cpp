//
//  CardDeck.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "CardDeck.hpp"
CardDeck* CardDeck::myCDeck = nullptr;
bool CardDeck::roundOverShuffle = false;

CardDeck& CardDeck::make_CardDeck(){
    if(myCDeck == nullptr || roundOverShuffle == true){
        cout<<"generating new game board"<<endl;
        delete(myCDeck);
        myCDeck = nullptr;
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
            if (l == 5){
                cout<<"error occured during giving pos"<<endl;
            }
        }
        return *myCDeck;
    }
    else{
        cout<<"returning previous game board"<<endl;
        return *myCDeck;
    }
}
