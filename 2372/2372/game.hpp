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
#include "player.hpp"
#include "card.hpp"
#include "board.hpp"
using namespace std;
static int nextPlayer =0;
class Game{
    Card* prevCard=nullptr;
    Card* currentCard=nullptr;
    int gameRound=1;
    bool skipping=false;
    Letter blockedLetter =Letter::C;
    Number blockedNumber = Number::three;
    
public:
    Board gameBoard;
    int numOfPlayer = 0;
    Player* topPlayer;
    Player* bottomPlayer;
    Player* leftPlayer;
    Player* rightPlayer;
    Game() = default;
    int getRound() const {return gameRound;}
    
    void nextRound(){
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
    
    bool getSkip(){
        return skipping;
    }
    
    void setSkip(bool skip){
        skipping=skip;
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
    Player& getWinner () const{
        if(numOfPlayer == 2){
            if(topPlayer->isActive() && !bottomPlayer->isActive() ){
                return *topPlayer;
            }
            else if(!topPlayer->isActive() && bottomPlayer->isActive() ){
                return * bottomPlayer;
            }
            
        }
        if(numOfPlayer == 3){
            if(topPlayer->isActive() && !bottomPlayer->isActive() && !leftPlayer->isActive() ){
                return *topPlayer;
            }
            else if(!topPlayer->isActive() && bottomPlayer->isActive() && !leftPlayer->isActive() ){
                return * bottomPlayer;
            }
            else if(!topPlayer->isActive() && !bottomPlayer->isActive() && leftPlayer->isActive() ){
                return *leftPlayer;
            }
        }
        if(numOfPlayer == 4){
            if(topPlayer->isActive() && !bottomPlayer->isActive() && !leftPlayer->isActive() && !rightPlayer->isActive()){
                return *topPlayer;
            }
            else if(!topPlayer->isActive() && bottomPlayer->isActive() && !leftPlayer->isActive() && !rightPlayer->isActive()){
                return * bottomPlayer;
            }
            else if(!topPlayer->isActive() && !bottomPlayer->isActive() && leftPlayer->isActive() && !rightPlayer->isActive()){
                return *leftPlayer;
            }
            else if(!topPlayer->isActive() && !bottomPlayer->isActive() && !leftPlayer->isActive() && rightPlayer->isActive()){
                return *rightPlayer;
            }
        }
        return *topPlayer;
    }
    
    Card* chooseCard(){
        bool valid= false;
        Letter a=Letter::A;
        Number z=Number::one;
        cout<<"Please input the character for rows: "<<endl;
        while(!valid){
        char r;
        cin>>r;
        r= toupper(r);
 
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
        cout<<"please input the number for column: "<<endl;
        cin>>c;

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
        if(a == Letter::C && z== Number::three){
            cout<<"You have entered an invalid card position, please retry......"<<endl;
            valid=false;
        }
        else{
            valid=true;
            }
        }
         return gameBoard.getCard(a,z);
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
    
    bool penguin(const Player& p){
            cout<<"Player " << p.getName()<< " you have turned up a Penguin!!!!! You can turn an face-up card to face down."<<endl;
            Card* chosen= chooseCard();
            while(gameBoard.isFaceUp(chosen->getLetter(), chosen->getNumber())==false){
                cout<<"PLease re-enter a card position as the card in position is still face down"<<endl;
                chosen= chooseCard();
            }
                gameBoard.turnFaceDown(chosen->getLetter(), chosen->getNumber());
                return true;
    }
    
    Letter getBlockedLetter(){
        return blockedLetter;
    }
    Number getBlockedNumber(){
        return blockedNumber;
    }
    bool walrus(const Player& p){
        cout<<"Player " << p.getName()<< " you have turned up a Walrus!!!!! You can Block a Card."<<endl;
        Card* chosen= chooseCard();
        while(gameBoard.isFaceUp(chosen->getLetter(), chosen->getNumber())==true){
            cout<<"PLease re-enter a card position as the card in position is face up and cannot be blocked, Please retry....."<<endl;
             chosen= chooseCard();
        }
        blockedLetter=chosen->getLetter();
        blockedNumber=chosen->getNumber();
        cout<<"The card: "<<chosen->getLetter() <<" "<<chosen->getNumber() <<" is blocked for next player! .."<<endl;
        return true;
    }
    
    Card* crab(const Player& p){
        cout<<"Player " << p.getName()<< "  you have turned up a Crab!!!!! You need to turn up an another card now. Please input the Character for row: "<<endl;
        Card* chosen= chooseCard();
        if(gameBoard.isFaceUp(chosen->getLetter(), chosen->getNumber())==true){
            cout<<"PLease re-enter a card position as the card in position is already face up"<<endl;
            return nullptr;
        }
        else{
            gameBoard.turnFaceUp(chosen->getLetter(), chosen->getNumber());
            return gameBoard.getCard(chosen->getLetter(), chosen->getNumber());
        }
    }
    
    void turtle(){
        skipping=true;
    }
    
    bool octopus(Card* cardToSwap, const Player& p){
        cout<<"Player " << p.getName()<< ", you have turned up an octopus!!!!! Your chosen card will be swapped with a randomly chosen adjacent card!!! "<<endl;
        cout<<endl;
        cout<<endl;
        Letter a;
        Number z;
        a= cardToSwap->getLetter();
        z= cardToSwap->getNumber();
        int position= rand() % 4;
        bool swapFinish=false;
        while(!swapFinish){
            switch(position){
                case (0):
                    swapFinish=swap(0, cardToSwap);
                    break;
                case (1):
                    swapFinish=swap(1, cardToSwap);
                    break;
                case (2):
                    swapFinish=swap(2, cardToSwap);
                    break;
                case (3):
                    swapFinish=swap(3, cardToSwap);
                    break;
                default:
                    cout<<"wrong number"<<endl;
                    break;
            }
        }
        return true;
    }
    
    bool swap(int i, Card* swapper){
        Card* swapee;
        if(i==0){
            if(swapper->topAvailable){
                swapee=gameCdeck->getByPosition((Letter)(swapper->getLetter()-1), swapper->getNumber());
                gameCdeck->swap(swapper,swapee);
                swapee->setLetter((Letter)(swapper->getLetter()));
                swapper->setLetter((Letter)(swapee->getLetter()-1));
                cout<<"Successfully swapped with top side"<<endl;
                return true;
            }
            else{
                cout<<"The top side is not avilable, choosing another side..."<<endl;
                return false;
            }
        }
        if(i==1){
            if(swapper->bottomAvailable){
                swapee=gameCdeck->getByPosition((Letter)(swapper->getLetter()+1), swapper->getNumber());
                gameCdeck->swap(swapper,swapee);
                swapee->setLetter((Letter)(swapper->getLetter()));
                swapper->setLetter((Letter)(swapee->getLetter()+1));
                cout<<"Successfully swapped with bottom side"<<endl;
                return true;
            }
            else{
                cout<<"The bottom side is not avilable, choosing another side..."<<endl;
                return false;
            }
        }
        if(i==2){
            if(swapper->leftAvailable){
                swapee=gameCdeck->getByPosition((Letter)(swapper->getLetter()), (Number)(swapper->getNumber()-1));
                gameCdeck->swap(swapper,swapee);
                swapee->setNumber((Number)(swapper->getNumber()));
                swapper->setNumber((Number)(swapee->getNumber()-1));
                cout<<"Successfully swapped with left side"<<endl;
                return true;
            }
    
            else{
                cout<<"The left side is not available, choosing another side..."<<endl;
                return false;
            }
        }
        if(i==3){
            if(swapper->rightAvailable){
                swapee=gameCdeck->getByPosition((Letter)(swapper->getLetter()), (Number)(swapper->getNumber()+1));
                gameCdeck->swap(swapper,swapee);
                swapee->setNumber((Number)(swapper->getNumber()));
                swapper->setNumber((Number)(swapee->getNumber()+1));
                cout<<"Successfully swapped with right side"<<endl;
                return true;
            }
            else{
                cout<<"The right side is not available, choosing another side..."<<endl;
                return false;
            }
        }
        cout<<"integer for side is incorrect, please double check the program"<<endl;
        return false;
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
        Card* tempCard=currentCard;
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
