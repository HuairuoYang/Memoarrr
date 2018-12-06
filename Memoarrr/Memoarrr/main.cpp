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
    string i;
    cout<<"Please input any character to continue for player 1"<<endl;
    cin>>i;
    myGame->addPlayer(*A);
    cout<<"Please input any character to continue for player 2"<<endl;
    cin>>i;
    myGame->addPlayer(*B);
    cout<<"Please input any character to continue for player 3"<<endl;
    cin>>i;
    myGame->addPlayer(*C);
    cout<<"Please input any character to continue for player 4"<<endl;
    cin>>i;
    myGame->addPlayer(*D);
    cout<<"Please make sure every player is ready and input any character to continue"<<endl;
    cin>>i;
    cout<<*myGame<<endl;
    cout<<"Beginning the game"<<endl;
    int numberOfFaceUp=0;
    int numberOfActivePlayers=4;
    while(endOfGame==false){
        int numberOfCardsInRound=0;
    while(rules->roundOver(*myGame)==false){
        cout<<"This is the number of players: "<< numberOfActivePlayers<<endl;
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
            int pos=0;
            switch(r){
                case 'A':  pos=c-1;
                    break;
                case 'B':  pos=c+4;
                    break;
                case 'C':  pos=c+9;
                    break;
                case 'D':  pos=c+14;
                    break;
                case 'E':  pos=c+19;
                    break;
                default: break;
            }
            cout<<*myGame<<endl;
            numberOfCardsInRound++;
            cout<< a <<endl;
            cout<<z<<endl;
            cout<<"just index : "<<pos<<endl;
            cout<<"card pos:"<<gameCdeck->getByPosition(pos)->getPosition()<<endl;;
            myGame->setCurrentCard(gameCdeck->getByPosition(pos));
            if(numberOfCardsInRound>1){
                 if(rules->isValid(*myGame)==true){}
            else{
                cout<<"Its not a match"<<endl;
                playingNow.setDisplayMode(true);
                numberOfActivePlayers--;
                if(numberOfActivePlayers<2){
                    cout<<"this is the end of round1..............."<<endl;
                    myGame->roundFinish();
                    myGame->incRound();
                    cout<<"this is the end of round2..............."<<endl;
                    playingNow.addReward(*rDeck->getNext());
                    cout<<"this is the number of rubbies for this player: "<<playingNow.getNRubies()<<endl;
                    if(myGame->getRound()>6){
                        endOfGame=true;
                        cout<<"this is the end of round3..............."<<endl;
                    }
                }
            }
            }
            numberOfFaceUp++;
        }
    }
}
}
