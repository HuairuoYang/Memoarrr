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
using namespace std;

class Game{
 
    Card* prevCard=nullptr;
    Card* currentCard=nullptr;
    Card* tempCard=nullptr;
    int currentPlayer =0; //(0-4)
    int gameRound;

    std::vector<Player> gamePlayers;
    
public:
    Board gameBoard;
    int getRound() const {return gameRound;}
    
    void incRound(){
        gameRound++;
    }
    void addPlayer ( const Player& p){
        gamePlayers.push_back(p);
        if(p.getSideString()=="TOP"){
            gameBoard.turnFaceUp(Letter::A, Number::two);
            gameBoard.turnFaceUp(Letter::A, Number::three);
            gameBoard.turnFaceUp(Letter::A, Number::four);
        }
        if(p.getSideString()=="BOTTOM"){
            gameBoard.turnFaceUp(Letter::E, Number::two);
            gameBoard.turnFaceUp(Letter::E, Number::three);
            gameBoard.turnFaceUp(Letter::E, Number::four);
        }
        if(p.getSideString()=="LEFT"){
            gameBoard.turnFaceUp(Letter::B, Number::one);
            gameBoard.turnFaceUp(Letter::C, Number::one);
            gameBoard.turnFaceUp(Letter::D, Number::one);
        }
        if(p.getSideString()=="RIGHT"){
            gameBoard.turnFaceUp(Letter::B, Number::five);
            gameBoard.turnFaceUp(Letter::C, Number::five);
            gameBoard.turnFaceUp(Letter::D, Number::five);
        }
        cout<<gameBoard<<endl;
        gameBoard.reset();
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
        tempCard=currentCard;
        prevCard =tempCard;
        currentCard = gameCdeck->getByPosition(c->getLetter(),c->getNumber());
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
