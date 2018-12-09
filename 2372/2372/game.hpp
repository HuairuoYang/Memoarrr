//
//  Game.hpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <limits>
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
    Letter blockedLetter = Letter::C;
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
                topPlayer = &p;
                revealCardsForPlayer(*topPlayer);
                break;
            case (Side::bottom):
                bottomPlayer = &p;
                revealCardsForPlayer(*bottomPlayer);
                break;
            case (Side::right):
                rightPlayer= &p;
                revealCardsForPlayer(*rightPlayer);
                break;
            case (Side::left):
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

    Card* chooseCard(){
        bool valid= false;
        Letter a=Letter::A;
        Number z=Number::one;
        cout<<"Please input the position(eg: A1 or a1): "<<endl;
        while(!valid){
        char r;
        while(!(cin >> r)||(toupper(r)!='A'&&toupper(r)!='B'&&toupper(r)!='C'&&toupper(r)!='D'&&toupper(r)!='E')){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input invalid, try again"<<endl;
        }
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
                while(!(cin >> c)||c<1||c>5){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input invalid, try again"<<endl;
                }
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
        cout<<"Player " << p.getName()<< " you have turned up a Penguin!!!!!"<<endl;
        cout<<"You can turn an face-up card to face down."<<endl;
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
        cout<<"Player " << p.getName()<< " you have turned up a Walrus!!!!!"<<endl;
        cout<<" You can Block a Card."<<endl;
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
        cout<<"Player " << p.getName()<< "  you have turned up a Crab!!!!!"<<endl;
        cout<<" You need to turn up an another card now. Please input the Character for row: "<<endl;
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
        cout<<"Player " << p.getName()<< ", you have turned up an octopus!!!!!"<<endl;
        cout<<"Your chosen card will be swapped with a randomly chosen adjacent card!!! "<<endl;
        cout<<"-------Reminder:: the card will not be swapped to empty spots, it will not go over the edges, corners and the volcano card!!!!!!------"<<endl;
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
                    position= rand() % 4;
                    break;
                case (1):
                    swapFinish=swap(1, cardToSwap);
                    position= rand() % 4;
                    break;
                case (2):
                    swapFinish=swap(2, cardToSwap);
                    position= rand() % 4;
                    break;
                case (3):
                    swapFinish=swap(3, cardToSwap);
                    position= rand() % 4;
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
                
                switchPosition(swapee,swapper);
                swapper->resetAvailability();
                swapee->resetAvailability();
                gameCdeck->swap(swapper,swapee);
                swapee->setIndex((Letter)(swapper->getLetter()),(Number)swapper->getNumber());
                swapper->setIndex((Letter)(swapee->getLetter()-1),(Number)swapper->getNumber());
                adjustSwapMidAvailability(swapee);
                adjustSwapMidAvailability(swapper);
                cout<<"Successfully swapped with top side"<<endl;
        
                
                return true;
            }
            else{
                return false;
            }
        }
        if(i==1){
            if(swapper->bottomAvailable){
                swapee=gameCdeck->getByPosition((Letter)(swapper->getLetter()+1), swapper->getNumber());
                switchPosition(swapee,swapper);
                swapper->resetAvailability();
                swapee->resetAvailability();
                gameCdeck->swap(swapper,swapee);
                swapee->setIndex((Letter)(swapper->getLetter()), (Number)swapper->getNumber());
                swapper->setIndex((Letter)(swapee->getLetter()+1),(Number)swapper->getNumber());
                adjustSwapMidAvailability(swapee);
                adjustSwapMidAvailability(swapper);
                cout<<"Successfully swapped with bottom side"<<endl;
                return true;
            }
            else{
                return false;
            }
        }
        if(i==2){
            if(swapper->leftAvailable){
                swapee=gameCdeck->getByPosition((Letter)(swapper->getLetter()), (Number)(swapper->getNumber()-1));
                switchPosition(swapee,swapper);
                swapper->resetAvailability();
                swapee->resetAvailability();
                gameCdeck->swap(swapper,swapee);
                swapee->setIndex((Letter)swapper->getLetter(),(Number)(swapper->getNumber()));
                swapper->setIndex((Letter)swapper->getLetter(),(Number)(swapee->getNumber()-1));
                adjustSwapMidAvailability(swapee);
                adjustSwapMidAvailability(swapper);
                cout<<"Successfully swapped with left side"<<endl;
                return true;
            }
    
            else{
                return false;
            }
        }
        if(i==3){
            if(swapper->rightAvailable){
                swapee=gameCdeck->getByPosition((Letter)(swapper->getLetter()), (Number)(swapper->getNumber()+1));
                switchPosition(swapee,swapper);
                swapper->resetAvailability();
                swapee->resetAvailability();
                gameCdeck->swap(swapper,swapee);
                swapee->setIndex((Letter)swapper->getLetter(),(Number)(swapper->getNumber()));
                swapper->setIndex((Letter)swapper->getLetter(),(Number)(swapee->getNumber()+1));
                adjustSwapMidAvailability(swapee);
                adjustSwapMidAvailability(swapper);
                cout<<"Successfully swapped with right side"<<endl;
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
    
    bool switchPosition(Card* swappee, Card* swapper){
        if(swappee->isFaceUp()){
            gameBoard.cardsFaceup.erase(std::remove(gameBoard.cardsFaceup.begin(), gameBoard.cardsFaceup.end(), ((int)swapper->getLetter()*5 + (int)swapper->getNumber())), gameBoard.cardsFaceup.end());
            std::vector<int>::iterator it;
            it = find(gameBoard.cardsFaceup.begin(),gameBoard.cardsFaceup.end(),swappee->getLetter()*5+swappee->getNumber());
            gameBoard.cardsFaceup.at(it-gameBoard.cardsFaceup.begin()) =swapper->getLetter()*5+swapper->getNumber();
           
        }
        else{
            if(!gameBoard.cardsFaceup.empty()){
                gameBoard.cardsFaceup.erase(std::remove(gameBoard.cardsFaceup.begin(), gameBoard.cardsFaceup.end(), ((int)swapper->getLetter()*5 + (int)swapper->getNumber())), gameBoard.cardsFaceup.end());
            }
        }
         gameBoard.cardsFaceup.push_back(swappee->getLetter()*5+swappee->getNumber());
        return true;
    }
    
    bool roundFinish() const{
        int activeCount = 0;
        getPlayer(Side::top).isActive()?(activeCount++):(activeCount+=0);
        getPlayer(Side::bottom).isActive()?(activeCount++):(activeCount+=0);
        if(numOfPlayer>2){
            getPlayer(Side::left).isActive()?(activeCount++):(activeCount+=0);
            if(numOfPlayer>3){
                getPlayer(Side::right).isActive()?(activeCount++):(activeCount+=0);
            }
        }
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
    
    
    bool adjustSwapMidAvailability(Card* card){
        cout<<"Adjusting postion in process...."<<endl;
        Letter a=card->getLetter();
        Number z=card->getNumber();
        if (a==Letter::B&&z==Number::three){
            card->bottomAvailable=false;
        }
        if (a==Letter::C&&z==Number::two){
            card->rightAvailable=false;
        }
        if (a==Letter::C&&z==Number::four){
            card->leftAvailable=false;
        }
        if (a==Letter::D&&z==Number::three){
            card->topAvailable=false;
        }
        return true;
    }
};


#endif /* Game_hpp */
