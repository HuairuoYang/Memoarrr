//
//  Board.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "Board.hpp"

bool Board::isFaceUp(const Letter & let, const Number & num){
    if( 0<let<5 && 0<num<5){
         Card* c =  static_cast<Card*> (gameCdeck->getByPosition(((int)let -1)*5 +(int)num-1));
        return c->isFaceUp();
    }
    else{
        std::cout<<"OutOfRange error"<<std::endl;
        return false;
    }
}

bool Board::turnFaceUp(const Letter & let, const Number & num){
    if( 0<let<5 && 0<num<5){
        Card* c =  static_cast<Card*> (gameCdeck->getByPosition(((int)let -1)*5 +(int)num-1));
        
        c->turnFace(true);;
        return true;
    }
    else{
        std::cout<<"OutOfRange error"<<std::endl;
        return false;
    }
}
bool Board::turnFaceDown(const Letter & let, const Number & num){
    if( 0<let<5 && 0<num<5){
        Card* c =  static_cast<Card*> (gameCdeck->getByPosition(((int)let -1)*5 +(int)num-1));
         c->turnFace(false);
        return true;
    }
    else{
        std::cout<<"OutOfRange error"<<std::endl;
        return false;
    }
}
void Board::reset(){
    Card* c;
    for(int i=0;i<25;i++){
        c =  static_cast<Card*>(gameCdeck->getByPosition(i));
        c->turnFace(false);
    }
}
