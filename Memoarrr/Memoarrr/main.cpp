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
#include "CardDeck.hpp"
#include "Utils.hpp"
#include "Game.hpp"
#include "Rules.hpp"

using namespace std;

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
    string begin;
    cout<<"Please make sure every player is ready and input any character to begin the game-------------------"<<endl;
    cin>>begin;
    while (true){
        cout<<endl;
        cout<<endl;
        cout<<endl;
        string mode;
        cout<<"Please input expert for expert mode or any other words for normal mode: "<<endl;
        cin>>mode;
        
        //expert mode
        if(mode=="expert"){
            cout<<"You are in expert mode!!!!!!!!!!!!"<<endl;
            int numberOfFaceUp=0;
            int numberOfActivePlayers=4;
            while(rules->gameOver(*myGame)==false){
                int numberOfCardsInRound=0;
                myGame->getPlayer(Side::top).setActive(true);
                myGame->getPlayer(Side::bottom).setActive(true);
                myGame->getPlayer(Side::left).setActive(true);
                myGame->getPlayer(Side::right).setActive(true);
                numberOfActivePlayers=4;
                bool blocking=false;
                while(rules->roundOver(*myGame)==false){
                    cout<<endl;
                    cout<<endl;
//                    cout<<"Game status printing at beginning---------"<<endl;
//                    cout<<"This is the number of players: "<< numberOfActivePlayers<<endl;
//                    cout<<"This is the current round number: "<<myGame->getRound()<<endl;
//                    cout<<"This is the current number of Faceup for round: "<<numberOfFaceUp<<endl;
                    Player& playingNow = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                    //getting the next active player if the previous player have got a turtle
//                    cout<<"checking Blocking state: ----"<<blocking<<endl;
//                    cout<<"checking the skipping state: ----"<< myGame->getSkip()<<endl;
                    if(myGame->getSkip()){
                        cout<<"skipping the next player"<<endl;
                        cout<<"---------Player "<< playingNow.getName()<<", you are skipped!!! Please have the next player to play----------"<<endl;
                        playingNow = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                        cout<<playingNow.getName()<<": YOU ARE NEXT!!!!!!!!!!"<<endl;
                        myGame->setSkip(false);
                    }
                    cout<<endl;
                    cout<<endl;
                    cout<<"------------------Game phase for player: "<< playingNow.getName()<<"  --------------------"<<endl;
                    
                    Card* current;
                    //if the walrus is turned up, see if the blocked card is chosen to be turn face up
                    if(!blocking){
                        current=myGame->chooseCard();
                        while(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==true){
                            cout<<"PLease re-enter a card position as the card in position is already face up"<<endl;
                            current=myGame->chooseCard();
                        }
                    }
                    else{
                        bool blockedChosen=true;
                        cout<<"The card in position: "<<myGame->getBlockedLetter()<<" "<<myGame->getBlockedNumber()<<" is blocked for you to turn face up..."<<endl;
                        while(blockedChosen){
                            current=myGame->chooseCard();
                            if(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==true){
                                cout<<"PLease re-enter a card position as the card in position is already face up"<<endl;
                                blockedChosen=true;
                            }
                            else {
                                if(current->getNumber()==myGame->getBlockedNumber()&&current->getLetter()==myGame->getBlockedLetter()){
                                    cout<<"The card chosen is blocked! Please choose another card!"<<endl;
                                    blockedChosen=true;
                                }
                                else{
                                    blockedChosen=false;
                                    blocking=false;
                                }
                            }
                        }
                    }
                    
                    myGame->gameBoard.turnFaceUp(current->getLetter(), current->getNumber());
                    numberOfFaceUp++;
                    numberOfCardsInRound++;
                    FaceAnimal animal;
                    animal = (FaceAnimal)myGame->gameBoard.getCard(current->getLetter(), current->getNumber())->getAnimal();
                    //cout<<"This is the animal turned: !!!!   "<< current->getAnimalStr()<<endl;
                    myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
                    //switch case for skills for different cards
                    cout<<endl;
                    cout<<endl;
                    Card* cc;
                    bool wal= true;
                    switch(animal){
                        case (FaceAnimal::crab):
                            myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
                            cc= myGame->crab(playingNow);
                            current->setLetter(cc->getLetter());
                            current->setNumber(cc->getNumber());
                            break;
                        case (FaceAnimal::penguin):
                            if(numberOfFaceUp>1){
                                    myGame->penguin(playingNow);
                                }
                                numberOfFaceUp--;
                            break;
                        case (FaceAnimal::walrus):
                            while(wal){
                                wal=!myGame->walrus(playingNow);
                            }
                            blocking=true;
                            break;
                        case (FaceAnimal::turtle):
                            myGame->turtle();
                            break;
                        case (FaceAnimal::octopus):
                            myGame->octopus(current, playingNow);
                            break;
                        default:
                            break;
                    }
                    
                    //checking player and game status
                    //myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
                    //cout<<"This is the number of cards in roud!!!:  " << numberOfCardsInRound<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"------- Current game board and player status---------"<<endl;
                    if(numberOfCardsInRound>1){
                        if(rules->isValid(*myGame)==true){
                            cout<<*myGame<<endl;
                            cout<<"Congratulations!!! Your card have matched with the previous card!!!"<<endl;
                           // nextPlayer++;
                        }
                        else{
                            playingNow.setActive(false);
                            cout<<*myGame<<endl;
                            cout<<"Unfortuantely, its not a match. end of round for current player"<<endl;
                            cout<<endl;
                            cout<<endl;
                            cout<<"..................................................."<<endl;
                            cout<<endl;
                            cout<<endl;
                            numberOfActivePlayers--;
                            if(numberOfActivePlayers<2){
                                myGame->roundFinish();
                                myGame->nextRound();
                                cout<<"This is the end of this round..............."<<endl;
                                playingNow=myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                                cout<<"Congratulations! The winner for this round is: "<< playingNow.getName()<<endl;
                                playingNow.addReward(*rDeck->getNext());
                                cout<<"this is the number of rubbies for this player: "<<playingNow.getNRubies()<<endl;
                                numberOfFaceUp=0;
                                numberOfCardsInRound=0;
                            }
                        }
                    }
                    else{
                        cout<<*myGame<<endl;
                        cout<<"_______End of gaming phase for player: "<<playingNow.getName()<<"   ----------------------------"<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                    }
                }
            }
        
        cout<<"7 rounds expert mode end"<<endl;
        myGame->getPlayer(Side::top).setDisplayMode(true);
        myGame->getPlayer(Side::bottom).setDisplayMode(true);
        myGame->getPlayer(Side::left).setDisplayMode(true);
        myGame->getPlayer(Side::right).setDisplayMode(true);
        cout<<*myGame<<endl;
    }
    
    
    //normal mode
    else{
        int numberOfFaceUp=0;
        int numberOfActivePlayers=4;
        while(rules->gameOver(*myGame)==false){
          cout<<"Round: "<<myGame->getRound()<<"start======================================="<<endl;
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
                cout<<"Player "<<playingNow.getName()<<"======================="<<endl;;
                Card* current = myGame->chooseCard();
                if(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==true){
                    cout<<"PLease re-enter a card position as the card in position is already face up"<<endl;
                }
                else{
                    myGame->gameBoard.turnFaceUp(current->getLetter(), current->getNumber());
                    numberOfFaceUp++;
                    numberOfCardsInRound++;
                    myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
                    //cout<<"This is the number of cards in roud!!!:  " << numberOfCardsInRound<<endl;
                    if(numberOfCardsInRound>1){
                        if(rules->isValid(*myGame)==true){
                            cout<<*myGame<<endl;
                            cout<<"MATCH!!!!!"<<endl;
                           // nextPlayer++;
                        }
                        else{
                            playingNow.setActive(false);
                            cout<<*myGame<<endl;
                            cout<<"Its not a match"<<endl;
                            numberOfActivePlayers--;
                            if(numberOfActivePlayers<2){
                                myGame->roundFinish();
                                myGame->nextRound();
                                cout<<"this is the end of round..............."<<endl;
                                Player& winner = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                                winner.addReward(*rDeck->getNext());
                                cout<<winner.getName()<<" now has "<<winner.getNRubies()<<"Rubies ******************"<<endl;
                                
                                numberOfCardsInRound=0;
                            }
                        }
                    }
                    else{
                        cout<<*myGame<<endl;
                    }
                }
                if(numberOfFaceUp>23){
                    cout<<"shuffling all cards"<<endl;
                    gameCdeck->roundOverShuffle=true;
                    gameCdeck->make_CardDeck();
                    gameCdeck->roundOverShuffle=false;
                    gameCdeck->make_CardDeck();
                    myGame->gameBoard.reset();
                    numberOfFaceUp=0;
                    
                }
            }
        }
        cout<<"7 rounds NORMAL mode end"<<endl;
        myGame->getPlayer(Side::top).setDisplayMode(true);
        myGame->getPlayer(Side::bottom).setDisplayMode(true);
        myGame->getPlayer(Side::left).setDisplayMode(true);
        myGame->getPlayer(Side::right).setDisplayMode(true);
        cout<<*myGame<<endl;
    }
}


}
