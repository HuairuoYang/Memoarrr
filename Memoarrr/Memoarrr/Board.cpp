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
         Card* c =  static_cast<Card*> (gameCdeck->getByPosition(((int)let )*5 +(int)num));
        return c->isFaceUp();
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
     return false;
}

bool Board::turnFaceUp(const Letter & let, const Number & num){
   try{
        Card* c =  static_cast<Card*> (gameCdeck->getByPosition(((int)let)*5 +(int)num));
        
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
        Card* c =  static_cast<Card*> (gameCdeck->getByPosition(((int)let)*5 +(int)num));
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
    for(int i=0;i<25;i++){
        c =  static_cast<Card*>(gameCdeck->getByPosition(i));
        c->turnFace(false);
    }
}
