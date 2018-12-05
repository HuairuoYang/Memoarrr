//
//  Deck.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>

template <typename C>
class Deck
{
protected:
    std::vector<C*> deck;
    int iter = 0;
    
public:
    void shuffle(){
        std::random_shuffle(deck.begin(), deck.end());
    };
    bool isEmpty(){return deck.empty();}
    
    C* getNext() {
        if(isEmpty()){
            return nullptr;
        } else {
            C* next = deck.at(iter);
            iter++;
            return next;
        }
    };
    virtual ~Deck(){
        for(auto i : deck){
            delete(i);
        }
    }
    C* getByPosition(int p){
        if(isEmpty()||p > deck.size()){
            return nullptr;
        }
        else {
            C* pos = deck.at(p);
            return pos;
    
        }
    }
};

#endif /* Deck_hpp */
