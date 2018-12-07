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
    while (true){
        string mode;
        cout<<"Please input expert for expert mode or any other words for normal mode: "<<endl;
        cin>>mode;
        
        //expert mode
        if(mode=="expert"){
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
                    cout<<"This is the number of players: "<< numberOfActivePlayers<<endl;
                    cout<<"This is the current round number: "<<myGame->getRound()<<endl;
                    cout<<"This is the current number of Faceup for round: "<<numberOfFaceUp<<endl;
                    Player& playingNow = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                    //getting the next active player if the previous player have got a turtle
                    if(myGame->getSkip()){
                        playingNow = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                        myGame->setSkip(false);
                    }
                    Card* current;
                    
                    //if the walrus is turned up, see if the blocked card is chosen to be turn face up
                    if(!blocking){
                    current=myGame->chooseCard();
                    }
                    else{
                        bool blockedChosen=true;
                        while(blockedChosen){
                            current=myGame->chooseCard();
                            if(current->getNumber()==myGame->getBlockedNumber()&&current->getLetter()==myGame->getBlockedLetter()){
                                blockedChosen=true;
                            }
                            else{
                                blockedChosen=false;
                                blocking=false;
                            }
                    }
                        
                    while(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==false){
                        cout<<"PLease re-enter a card position as the card in position is already face up"<<endl;
                    }
                        myGame->gameBoard.turnFaceUp(current->getLetter(), current->getNumber());
                        numberOfFaceUp++;
                        numberOfCardsInRound++;
                        FaceAnimal animal;
                        animal = (FaceAnimal)myGame->gameBoard.getCard(current->getLetter(), current->getNumber())->getAnimal();
                        
                        //switch case for skills for different cards
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
                                    bool down=false;
                                    while(!down){
                                        down=myGame->penguin(playingNow);
                                    }
                                    numberOfFaceUp--;
                                }
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
                                
                                break;
                            default:
                                break;
                        }
                        myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
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
                                    myGame->nextRound();
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
                        Card* current = myGame->chooseCard();
                        if(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==true){
                            cout<<"PLease re-enter a card position as the card in position is already face up"<<endl;
                        }
                        else{
                            myGame->gameBoard.turnFaceUp(current->getLetter(), current->getNumber());
                            numberOfFaceUp++;
                            numberOfCardsInRound++;
                            myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
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
                                        myGame->nextRound();
                                        cout<<"this is the end of round..............."<<endl;
                                        playingNow.addReward(*rDeck->getNext());
                                        cout<<"this is the number of rubbies for this player: "<<playingNow.getNRubies()<<endl;
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


