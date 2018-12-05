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
