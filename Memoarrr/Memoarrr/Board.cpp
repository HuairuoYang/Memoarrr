//
//  Board.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "Board.hpp"

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
        return true;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
     return false;
}
void Board::reset(){
    Card* c;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            c =  static_cast<Card*>(gameCdeck->getByPosition((Letter)i,(Number)j));
            c->turnFace(false);
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
    c->setLetter(l);
    c->setNumber(n);
    if (gameCdeck->setByPosition(l,n,c)){
        cout<<"setCard successful"<<endl;
    }
    else{
        cout<<"setCard NOT successful"<<endl;
    }
}
