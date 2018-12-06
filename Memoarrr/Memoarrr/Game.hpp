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
    int gameRound=1;
    
    
public:
    Board gameBoard;
    int numOfPlayer = 0;
    Player* topPlayer;
    Player* bottomPlayer;
    Player* leftPlayer;
    Player* rightPlayer;
    Game() = default;
    int getRound() const {return gameRound;}
    
    void incRound(){
        gameRound++;
    }
    void addPlayer ( Player& p){
        switch (p.getSide()){
            case (Side::top):
                numOfPlayer++;
                topPlayer = &p;
                break;
            case (Side::bottom):
                numOfPlayer++;
                bottomPlayer = &p;
                break;
            case (Side::right):
                numOfPlayer++;
                rightPlayer= &p;
                break;
            case (Side::left):
                numOfPlayer++;
                leftPlayer= &p;
                break;
            default:
                break;
        }
    }
    
    Player& getPlayer(Side s){
        switch (s ){
            case (Side::top):
                return *topPlayer;
                break;
            case (Side::bottom):
                return *bottomPlayer;
                break;
            case (Side::right):
                return *rightPlayer;
                break;
            case (Side::left):
                return *leftPlayer;
                break;
            default:
                return *topPlayer;
                break;
        }
    }
    
    void revealCardsForPlayer(const Player& p){
        string i;
        if(p.getSideString()=="TOP"){
            cout<<"Please input any character to continue for player on the Top side"<<endl;
            cin>>i;
            gameBoard.turnFaceUp(Letter::A, Number::two);
            gameBoard.turnFaceUp(Letter::A, Number::three);
            gameBoard.turnFaceUp(Letter::A, Number::four);
        }
        if(p.getSideString()=="BOTTOM"){
            cout<<"Please input any character to continue for player on the Bottom side"<<endl;
            cin>>i;
            gameBoard.turnFaceUp(Letter::E, Number::two);
            gameBoard.turnFaceUp(Letter::E, Number::three);
            gameBoard.turnFaceUp(Letter::E, Number::four);
        }
        if(p.getSideString()=="LEFT"){
            cout<<"Please input any character to continue for player on the Left side"<<endl;
            cin>>i;
            gameBoard.turnFaceUp(Letter::B, Number::one);
            gameBoard.turnFaceUp(Letter::C, Number::one);
            gameBoard.turnFaceUp(Letter::D, Number::one);
        }
        else if(p.getSideString()=="RIGHT"){
            cout<<"Please input any character to continue for player on the Right side"<<endl;
            cin>>i;
            gameBoard.turnFaceUp(Letter::B, Number::five);
            gameBoard.turnFaceUp(Letter::C, Number::five);
            gameBoard.turnFaceUp(Letter::D, Number::five);
        }
        cout<<gameBoard<<endl;
        gameBoard.reset();
    }
    
    
    bool roundFinish() const{
        int activeCount = 0;
        
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
        switch (g.numOfPlayer) {
            case 1:
                os<<*g.topPlayer<<endl;
                break;
            case 2:
                os<<*g.topPlayer<<endl;
                os<<*g.bottomPlayer<<endl;
                break;
            case 3:
                os<<*g.topPlayer<<endl;
                os<<*g.bottomPlayer<<endl;
                os<<*g.leftPlayer<<endl;
                break;
            case 4:
                os<<*g.topPlayer<<endl;
                os<<*g.bottomPlayer<<endl;
                os<<*g.leftPlayer<<endl;
                os<<*g.rightPlayer<<endl;
                break;
            default:
                break;
        }
        return os;
    }
    
    
};


#endif /* Game_hpp */
