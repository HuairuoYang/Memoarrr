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
    while (true){
        string mode;
        cout<<"Please input expert for expert mode or any other words for normal mode: "<<endl;
        cin>>mode;
    
    int numberOfFaceUp=0;
    int numberOfActivePlayers=4;
    while(endOfGame==false){
        cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
        if(!endOfGame){
            cout<<"The game has not ended yet!, the status of the game is: "<<endOfGame<<endl;
        }
        int numberOfCardsInRound=0;
        myGame->getPlayer(Side::top).setActive(true);
        myGame->getPlayer(Side::bottom).setActive(true);
        myGame->getPlayer(Side::left).setActive(true);
        myGame->getPlayer(Side::right).setActive(true);
        numberOfActivePlayers=4;
        
    while(rules->roundOver(*myGame)==false){
        cout<<"This is the number of players: "<< numberOfActivePlayers<<endl;
        cout<<"This is the current round number: "<<myGame->getRound()<<endl;
         cout<<"This is the current number of Faceup for round: "<<numberOfFaceUp<<endl;
        Player& playingNow = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
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
            
            numberOfCardsInRound++;
            myGame->setCurrentCard(gameCdeck->getByPosition(a,z));
            cout<<"This is the number of cards in roud!!!:  " << numberOfCardsInRound<<endl;
            if(numberOfCardsInRound>1){
                 if(rules->isValid(*myGame)==true){
                     cout<<*myGame<<endl;
                     cout<<"MATCH!!!!!"<<endl;
                     currentPlayer++;
                 }
                 else{
                     playingNow.setActive(false);
                     cout<<*myGame<<endl;
                     cout<<"Its not a match"<<endl;
                     
                     numberOfActivePlayers--;
                     if(numberOfActivePlayers<2){
                         myGame->roundFinish();
                         myGame->incRound();
                         cout<<"this is the end of round..............."<<endl;
                         playingNow.addReward(*rDeck->getNext());
                         cout<<"this is the number of rubbies for this player: "<<playingNow.getNRubies()<<endl;
                         numberOfFaceUp=0;
                         numberOfCardsInRound=0;
                        }
                    }
                }
            else{
                cout<<*myGame<<endl;
            }
            }
        }
    }
}
}
