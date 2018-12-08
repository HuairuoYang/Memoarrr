//
//  Rules.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "Rules.hpp"

bool Rules::isValid(const Game& g){
    if(g.getPreviousCard()->getAnimal() ==g.getCurrentCard()->getAnimal() || g.getPreviousCard()->getColor() ==g.getCurrentCard()->getColor()){
        return true;
    }
    else{
        return false;
    }
}

bool Rules::gameOver(const Game& g){
    if(g.getRound() == 7){
        endOfGame = true;
        return endOfGame;
    }
    else{
        endOfGame = false;
        return endOfGame;
    }
}
bool Rules::roundOver(const Game& g){
    return g.roundFinish();
}
const Player& Rules::getNextPlayer(const Game& g){
     Player* temp =nullptr;
     while(temp == nullptr || !temp->isActive()){

         switch (nextPlayer){
             case 0:
                 cout<<"getting top"<<endl;
                 temp = &g.getPlayer(Side::top);
                 break;
             case 1:
                 cout<<"getting bot"<<endl;
                 temp = &g.getPlayer(Side::bottom);
                 break;
             case 2:
                 cout<<"getting left"<<endl;
                 temp = &g.getPlayer(Side::left);
                 break;
             case 3:
                 cout<<"getting right"<<endl;
                 temp = &g.getPlayer(Side::right);
                 break;
             default:
                 temp = nullptr;
                 break;
         }
         nextPlayer++;
         if (nextPlayer ==g.numOfPlayer){
             nextPlayer = 0;
         }
         cout<<"next player : "<<nextPlayer<<endl;
         
     }
     return *temp;
     
}
