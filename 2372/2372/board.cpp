//
//  Board.cpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
//

#include "board.hpp"
vector <int> Board::cardsFaceup ={};

bool Board::isFaceUp(const Letter & let, const Number & num){
    try{
         Card* c =  static_cast<Card*> (gameCdeck->getByPosition(let,num));
        return c->isFaceUp();
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
     return false;
}

bool Board::turnFaceUp(const Letter & let, const Number & num){
   try{
        Card* c =  static_cast<Card*> (gameCdeck->getByPosition(let,num));
        
        c->turnFace(true);
           cardsFaceup.push_back((int)let*5 + (int)num);
       
       
        return true;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
     return false;
}
bool Board::turnFaceDown(const Letter & let, const Number & num){
    try{
        Card* c =  static_cast<Card*> (gameCdeck->getByPosition(let,num));
         c->turnFace(false);
        if(!cardsFaceup.empty()){
            cardsFaceup.erase(std::remove(cardsFaceup.begin(), cardsFaceup.end(), ((int)let*5 + (int)num)), cardsFaceup.end());
        }
        return true;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
     return false;
}
void Board::reset(){
    gameCdeck->make_CardDeck();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            turnFaceDown((Letter)i,(Number) j);
        }
    }
}

Card* Board::getCard(const Letter& l, const Number& n){
    try{
        return gameCdeck->getByPosition(l,n);
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        return nullptr;
    }
}
void Board::setCard( const Letter& l, const Number& n, Card* c){
    c->setIndex(l,n);
    if (gameCdeck->setByPosition(l,n,c)){
        cout<<"setCard successful"<<endl;
    }
    else{
        cout<<"setCard NOT successful"<<endl;
    }
}
