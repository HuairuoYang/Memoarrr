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

//Design a class Deck<C> as an abstract factory class that will be used to create a set of cards or a set of rewards. The type parameter <C> is intended to be one of {Card|Reward}. The class will need the following methods:
//• void shuffle() shuffles the cards in the deck. You must use the function std::random_shuffle from the standard template library.
//• C* getNext() returns the next card or reward by pointer. Will return nullptr if no more cards or rewards are available.
//• bool isEmpty() const returns true if the deck is empty.

template <typename C>
class Deck
{
protected:
    std::vector<C*> deck;
    int iter = 0;
    
public:
    virtual void shuffle()= 0;
    bool isEmpty(){return deck.empty();}
    
    C* getNext(){
        if(isEmpty()){
            return nullptr;
        } else {
            C* card = deck.at(iter);
            iter++;
            return card;
        }
    };
    virtual ~Deck(){
        for(auto i : deck){
            delete(deck[i]);
        }
    }
};

#endif /* Deck_hpp */
