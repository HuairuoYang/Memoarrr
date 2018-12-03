//
//  Game.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "Player.hpp"
#include "Card.hpp"
#include "Board.hpp"

class Game{
 
    Card* prevCard;
    Card* currentCard;
    int currentPlayer; //(0-4)
    int gameRound;
    std::vector<Player> gamePlayers;
    
public:
    Board gameBoard;
    int getRound() const {return gameRound;}
    
    void incRound(){
        gameRound++;
    }
    void addPlayer( const Player& p){
        gamePlayers.push_back(p);
    }
    Player& getPlayer(){
        if(currentPlayer ==4){
            currentPlayer = 0;
        }
        return (gamePlayers[currentPlayer++]);
    }
    
    bool roundFinish() const{
        int activeCount = 0;
        for(auto i: gamePlayers){
            (i.isActive())?(activeCount+=1):(activeCount+=0);
        }
        return (activeCount ==1);
    }
    
    const Card* getPreviousCard() const{return prevCard;}
    const Card* getCurrentCard() const{return currentCard;}
    void setCurrentCard( const Card* c){
        prevCard = currentCard;
        int pos = c->getPosition();
        currentCard = gameCdeck->getByPosition(pos);
    }
    friend std::ostream& operator<<(std::ostream& os,Game & g) {
        os << g.gameBoard;
        for(auto i: g.gamePlayers){
            os<<(i);
        }
        return os;
    }
};


#endif /* Game_hpp */
