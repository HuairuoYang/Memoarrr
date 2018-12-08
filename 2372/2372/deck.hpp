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
#include <iostream>
#include "utils.hpp"
using namespace std;
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
        if(deck.empty()){
            throw std::out_of_range("out of range");
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
    C* getByPosition( const Letter& l, const Number& n){
        if(deck.empty() ){
            std::cout<<"empty deck"<<std::endl;
            return nullptr;
        }
        if( l>5 || l<0 || n>5 || n<0 || (int)l*5+(int)n>deck.size()){
            throw std::out_of_range("out of range");
            return nullptr;
        }
        else {
            C* pos = deck.at((int)l*5+(int)n);
            return pos;
    
        }
    }
    
    bool setByPosition( const Letter& l, const Number& n, C* c){
        if(isEmpty() ){
            std::cout<<"empty deck"<<std::endl;
            return nullptr;
        }
        if( l>5 || l<0 || n>5 || n<0 || (int)l*5+(int)n>deck.size()){
            throw std::out_of_range("out of range");
            return false;
        }
        else {
            deck.at((int)l*5+(int)n) = c;
            return true;
        }
    }
    
    bool swap(C* original, C* swapee){
        iter_swap(deck.begin()+(original->getLetter()*5+original->getNumber()), deck.begin()+(swapee->getLetter()*5+swapee->getNumber()));
        return true;
    }
    
};

#endif /* Deck_hpp */
