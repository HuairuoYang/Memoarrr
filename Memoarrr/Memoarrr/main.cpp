//
//  main.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include <iostream>
#include <string>
#include <iostream>
#include "Board.hpp"
#include "Utils.hpp"
#include "Game.hpp"
#include "Rules.hpp"

using namespace std;

static bool expertMode;

int main(int argc, const char * argv[]) {
    Rules* rules= new Rules();
    cout << "Hello, World!\n"<<endl;
    Game* myGame = new Game();
    cout<<*myGame<<endl;
    
    Player* A = new Player("AA",(Side::top));
    Player* B = new Player("BB",(Side::bottom));
    Player* C = new Player("CC",(Side::left));
    Player* D = new Player("DD",(Side::right));
    
    //Adding the players and temporily revealing the three cards directly in front of the player

    myGame->addPlayer(*A);
    myGame->addPlayer(*B);
    myGame->addPlayer(*C);
    myGame->addPlayer(*D);
    cout<<*myGame<<endl;
    
    cout<<"Beginning the game"<<endl;
    
    // Variables initialization
    int numberOfFaceUp=0;
    int numberOfActivePlayers=4;
    while(endOfGame==false){
        if(!endOfGame){
            cout<<"The game has not ended yet!, the status of the game is: "<<endOfGame<<endl;
        }
        int numberOfCardsInRound=0;
        myGame->gamePlayers.at(0).setActive(true);
        myGame->gamePlayers.at(1).setActive(true);
        myGame->gamePlayers.at(2).setActive(true);
        myGame->gamePlayers.at(3).setActive(true);
        numberOfActivePlayers=4;
        
    while(rules->roundOver(*myGame)==false){
        cout<<"This is the number of players: "<< numberOfActivePlayers<<endl;
        cout<<"This is the current round number: "<<myGame->getRound()<<endl;
         cout<<"This is the current number of Faceup for round: "<<numberOfFaceUp<<endl;
        Player& playingNow= myGame->getPlayer();
        while(playingNow.isActive()==false){
            playingNow= myGame->getPlayer();
            }
        char r;
        cout<<"Player " << playingNow.getName()<< ", Please input the Character for row "<<endl;
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
        if(myGame->gameBoard.isFaceUp(a, z)==true || (a == Letter::C && z== Number::three)){
            cout<<"PLease re-enter a card position as the card in position is already face up or invalid"<<endl;
        }
        else{
            myGame->gameBoard.turnFaceUp(a, z);
            numberOfFaceUp++;
            cout<<*myGame<<endl;
            numberOfCardsInRound++;
            myGame->setCurrentCard(gameCdeck->getByPosition(a,z));
            if(numberOfCardsInRound>1){
                 if(rules->isValid(*myGame)==true){}
                 else{
                     cout<<"Its not a match"<<endl;
                     playingNow.setActive(false);
                     numberOfActivePlayers--;
                     if(numberOfActivePlayers<2){
                         myGame->roundFinish();
                         myGame->incRound();
                         cout<<"this is the end of round..............."<<endl;
                         playingNow.addReward(*rDeck->getNext());
                         cout<<"this is the number of rubbies for this player: "<<playingNow.getNRubies()<<endl;
                         numberOfFaceUp=0;
                        }
                    }
                }
            }
        }
    }
}

