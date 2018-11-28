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
//Design a class Game that encapsulates the current state of the game and it will have a class variable of type Board. It is responsible to print the current state of the game.
//• int getRound() returns a number between 0 and 6 corresponding to the current round of the game
//• void addPlayer( const Player& ) which adds a Player to this game.
//• Player& getPlayer()
//• const Card* getPreviousCard()
//• const Card* getCurrentCard()
//• void setCurrentCard( const Card*)
//A game must be printable with the insertion operator cout << game. It should display the board and all players.

class Game{
    Card* prevCard;
    Card* currentCard;
    int gameRound;
public:
    Board gameBoard;


    
    vector<Player> gamePlayers;
    int getRound(){return gameRound;}
    void incRound(){gameRound++;}
    void addPlayer( const Player& p){gamePlayers.push_back(p);}
    Player& getPlayer(){    };
    const Card* getPreviousCard(){return prevCard;}
    const Card* getCurrentCard(){return currentCard;}
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
