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
        cout<<"match"<<endl;
        return true;
    }
    else{
        cout<<"not match"<<endl;
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
 Player& Rules::getNextPlayer(const Game& g){
    switch (currentPlayer){
        case 0:
            currentPlayer++;
            if (currentPlayer == g.numOfPlayer){
                currentPlayer =0;
            }
            return *g.topPlayer;
            break;
        case 1:
            currentPlayer++;
            if (currentPlayer == g.numOfPlayer){
                currentPlayer =0;
            }
            return *g.bottomPlayer;
            break;
        case 2:
            currentPlayer++;
            if (currentPlayer == g.numOfPlayer){
                currentPlayer =0;
            }
            return *g.leftPlayer;
            break;
        case 3:
            currentPlayer++;
            if (currentPlayer == g.numOfPlayer){
                currentPlayer =0;
            }
            return *g.rightPlayer;
            break;
        default:
            return *g.topPlayer;
            break;
    }
}
