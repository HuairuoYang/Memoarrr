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
static int currentPlayer =0;
class Game{
    
    Card* prevCard=nullptr;
    Card* currentCard=nullptr;
    Card* tempCard=nullptr;
    int gameRound=1;
    Card* blocked=nullptr;
    bool blockState=false;

    
    
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
                revealCardsForPlayer(*topPlayer);
                break;
            case (Side::bottom):
                numOfPlayer++;
                bottomPlayer = &p;
                revealCardsForPlayer(*bottomPlayer);
                break;
            case (Side::right):
                numOfPlayer++;
                rightPlayer= &p;
                revealCardsForPlayer(*rightPlayer);
                break;
            case (Side::left):
                numOfPlayer++;
                leftPlayer= &p;
                revealCardsForPlayer(*leftPlayer);
                break;
            default:
                break;
        }
        
    }
    
    Player& getPlayer  (Side s) const{
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
    
    bool penguin(Number a, Letter z, bool act){
        if(!act){
            if(gameBoard.isFaceUp(z, a)){
                gameBoard.turnFaceDown(z, a);
                cout<<this<<endl;
                return true;
            }
            else{
                cout<<"Please double check your input as the card is not turned face up"<<endl;
                return false;}
        }
        return false;
    }
    
    void walrus(Letter a, Number z){
        blocked= gameBoard.getCard(a, z);
        blockState=true;
    }
    
    Card* crab(const Player& p){
        char r;
        cout<<"Player " << p.getName()<< " you have turned up a Penguim!!!!! You need to turn up an another card now. Please input the Character for row: "<<endl;
        cin>>r;
        r= toupper(r);
        Letter a=Letter::A;
        switch(r){
            case 'A':
                a = Letter::A;
                break;
            case 'B':
                a = Letter::B;
                break;
            case 'C':
                a = Letter::C;
                break;
            case 'D':
                a = Letter::D;
                break;
            case 'E':
                a = Letter::E;
                break;
            default: break;
        }
        int c;
        cout<<"please input the number for column"<<endl;
        cin>>c;
        Number z=Number::one;
        switch(c){
            case 1:
                z = Number::one;
                break;
            case 2:
                z = Number::two;
                break;
            case 3:
                z = Number::three;
                break;
            case 4:
                z = Number::four;
                break;
            case 5:
                z = Number::five;
                break;
            dafault: break;
        }
        if(gameBoard.isFaceUp(a, z)==true || (a == Letter::C && z== Number::three)){
            cout<<"PLease re-enter a card position as the card in position is already face up or invalid"<<endl;
            return nullptr;
        }
        else{
            gameBoard.turnFaceUp(a, z);
            return gameBoard.getCard(a, z);
        }
    }
    
    bool roundFinish() const{
        int activeCount = 0;
        getPlayer(Side::top).isActive()?(activeCount++):(activeCount+=0);
        getPlayer(Side::bottom).isActive()?(activeCount++):(activeCount+=0);
        getPlayer(Side::left).isActive()?(activeCount++):(activeCount+=0);
        getPlayer(Side::right).isActive()?(activeCount++):(activeCount+=0);
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
