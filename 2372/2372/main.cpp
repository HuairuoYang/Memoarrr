//
//  main.cpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
//

#include <iostream>
#include <string>
#include <limits>
#include <iostream>
#include "board.hpp"
#include "carddeck.hpp"
#include "utils.hpp"
#include "game.hpp"
#include "rules.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Rules* rules= new Rules();
    Game* myGame = new Game();
    string mode;
    cout<<"Please input \"expert\" for expert mode or any for normal mode: "<<endl;
    cin>>mode;
    expertMode = (mode == "expert");
    cout<<"Please enter the number of players (2-4): "<<endl;
    while(!(cin >> myGame->numOfPlayer)||myGame->numOfPlayer < 2 || myGame->numOfPlayer>4){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input invalid, try again"<<endl;
    }
    string topName;
    cout<<"Please enter the name for Player at top:"<<endl;
    cin >>topName;
    Player* A = new Player(topName,(Side::top));
    myGame->addPlayer(*A);
    string botName;
    cout<<"Please enter the name for Player at bottom:"<<endl;
    cin >>botName;
    Player* B = new Player(botName,(Side::bottom));

    myGame->addPlayer(*B);
    if(myGame->numOfPlayer>2){
        string leftName;
        cout<<"Please enter the name for Player at left:"<<endl;
        cin >>leftName;
        Player* C = new Player(leftName,(Side::left));
        myGame->addPlayer(*C);
        if(myGame->numOfPlayer>3){
            string rightName;
            cout<<"Please enter the name for Player at right:"<<endl;
            cin >>rightName;
            Player* D = new Player(rightName,(Side::right));
            myGame->addPlayer(*D);
        }
    }
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    //Adding the players and temporily revealing the three cards directly in front of the player
    cout<<"========GAME START========"<<endl;

        cout<<" "<<endl;
        //expert mode
        if(expertMode){
            int numberOfFaceUp=0;
            int numberOfActivePlayers=myGame->numOfPlayer;;
            while(rules->gameOver(*myGame)==false){
                char a;
                cout<<"EXPERT: Enter any key to start round: "<<myGame->getRound()<<endl;
                cin>>a;
                cout<<"********EXPERT: Round "<<myGame->getRound()<<" start********"<<endl;
                int numberOfCardsInRound=0;
                myGame->getPlayer(Side::top).setActive(true);
                myGame->getPlayer(Side::bottom).setActive(true);
                if(myGame->numOfPlayer>2){
                    myGame->getPlayer(Side::left).setActive(true);
                    if(myGame->numOfPlayer >3){
                        myGame->getPlayer(Side::right).setActive(true);
                    }
                }
                numberOfActivePlayers=myGame->numOfPlayer;
                bool blocking=false;
                while(rules->roundOver(*myGame)==false){
                    cout<<endl;
                    cout<<endl;
                    Player* playingNow = &myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                    if(myGame->getSkip()){
                        cout<<"EXPERT: skipping the next player  "<< playingNow->getName()<<endl;
                        playingNow = &myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                        myGame->setSkip(false);
                    }
                    cout<<endl;
                    cout<<endl;
                    cout<<*myGame<<endl;
                    cout<<"--------EXPERT: Player "<<playingNow->getName()<<" start--------"<<endl;;


                    Card* current = nullptr;
                    //if the walrus is turned up, see if the blocked card is chosen to be turn face up
                    if(!blocking){
                        current=myGame->chooseCard();
                        while(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==true){
                            cout<<"Already face up"<<endl;
                            current=myGame->chooseCard();
                        }
                    }
                    else{
                        bool blockedChosen=true;
                        cout<<"EXPERT: The card : "<<myGame->getBlockedLetter()<<" "<<myGame->getBlockedNumber()<<" is blocked"<<endl;
                        while(blockedChosen){
                            current=myGame->chooseCard();
                            if(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==true){
                                cout<<"EXPERT: Already face up"<<endl;
                                blockedChosen=true;
                            }
                            else {
                                if(current->getNumber()==myGame->getBlockedNumber()&&current->getLetter()==myGame->getBlockedLetter()){
                                    cout<<"EXPERT: The card is blocked! Please choose another card!"<<endl;
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
                    bool crabturned=false;
                    cout<<"--------Player: "<<playingNow->getName()<<" skills--------"<<endl;
                    cout<<*myGame<<endl;
                    while(!crabturned){
                        switch(animal){
                            case (FaceAnimal::crab):
                                myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
                                cc= myGame->crab(*playingNow);
                                numberOfFaceUp++;
                                numberOfCardsInRound++;
                                current=cc;
                                myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
                                animal = (FaceAnimal)myGame->gameBoard.getCard(current->getLetter(), current->getNumber())->getAnimal();
                                crabturned=false;
                                break;
                            case (FaceAnimal::penguin):
                                if(numberOfFaceUp>1){
                                    myGame->penguin(*playingNow);
                                    numberOfFaceUp--;
                                }
                                else{
                                    cout<<"You have a penguin but its the first card in round, you cannot flip a card"<<endl;

                                }

                                crabturned=true;
                                break;
                            case (FaceAnimal::walrus):
                                if(numberOfFaceUp<24){
                                    while(wal){
                                        wal=!myGame->walrus(*playingNow);
                                    }
                                }
                                blocking=true;
                                crabturned=true;
                                break;
                            case (FaceAnimal::turtle):
                                myGame->turtle();
                                crabturned=true;
                                break;
                            case (FaceAnimal::octopus):
                                myGame->octopus(current, *playingNow);
                                crabturned=true;
                                break;
                            default:
                                break;
                        }
                    }
                    if(numberOfCardsInRound<2){
                        cout<<"--------Player: "<<playingNow->getName()<<" finished--------"<<endl;
                    }
                    else{
                        if(rules->isValid(*myGame)==true){
                            cout<<*myGame<<endl;
                            cout<<"EXPERT: It is a match!"<<endl;
                            cout<<"--------Player: "<<playingNow->getName()<<" finished--------"<<endl;
                            // nextPlayer++;
                        }
                        else{
                            playingNow->setActive(false);
                            cout<<*myGame<<endl;
                            cout<<"EXPERT: It is not a match. "<<playingNow->getName()<<" is out."<<endl;
                             cout<<"--------Player: "<<playingNow->getName()<<" finished--------"<<endl;
                            numberOfActivePlayers--;
                            if(numberOfActivePlayers<2){
                                playingNow= &myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                                cout<<endl;
                                cout<<endl;
                                cout<<"EXPERT: Congratulations! The winner for this round is: "<< playingNow->getName()<<endl;
                                playingNow->addReward(*rDeck->getNext());
                                 cout<<"********EXPERT: Round "<<myGame->getRound()<<" finish********"<<endl;
                                cout<<endl;
                                cout<<endl;
                                myGame->roundFinish();
                                myGame->nextRound();
                                myGame->setSkip(false);
                                numberOfCardsInRound=0;
                            }
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
            cout<<"##########EXPERT: GAME OVER##########"<<endl;
            cout<<"EXPERT: 7 rounds expert mode end"<<endl;
            myGame->getPlayer(Side::top).setDisplayMode(true);
            myGame->getPlayer(Side::bottom).setDisplayMode(true);
            if(myGame->numOfPlayer>2){
                myGame->getPlayer(Side::left).setDisplayMode(true);
                if(myGame->numOfPlayer>3){
                    myGame->getPlayer(Side::right).setDisplayMode(true);
                }
            }
            cout<<*myGame<<endl;
            cout<<"##########EXPERT: GAME OVER##########"<<endl;
        }


        //normal mode
        else{
            int numberOfFaceUp=0;
            int numberOfActivePlayers=myGame->numOfPlayer;
            while(rules->gameOver(*myGame)==false){
                char a;
                cout<<"Enter any key to start round: "<<myGame->getRound()<<endl;
                cin>>a;
                cout<<"********Round "<<myGame->getRound()<<" start********"<<endl;
                     cout<<*myGame<<endl;
                int numberOfCardsInRound=0;
                myGame->getPlayer(Side::top).setActive(true);
                myGame->getPlayer(Side::bottom).setActive(true);
                if(myGame->numOfPlayer>2){
                    myGame->getPlayer(Side::left).setActive(true);
                    if(myGame->numOfPlayer >3){
                        myGame->getPlayer(Side::right).setActive(true);
                    }
                }
                numberOfActivePlayers=myGame->numOfPlayer;

                while(rules->roundOver(*myGame)==false){
                    cout<<endl;
                    cout<<endl;
                    Player& playingNow = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                    cout<<"--------Player "<<playingNow.getName()<<" start--------"<<endl;;
                    Card* current = myGame->chooseCard();
                    if(myGame->gameBoard.isFaceUp(current->getLetter(), current->getNumber())==true){
                        cout<<"Already face up"<<endl;
                    }
                    else{
                        myGame->gameBoard.turnFaceUp(current->getLetter(), current->getNumber());
                        numberOfFaceUp++;
                        numberOfCardsInRound++;
                        myGame->setCurrentCard(gameCdeck->getByPosition(current->getLetter(), current->getNumber()));
                        //cout<<"This is the number of cards in roud!!!:  " << numberOfCardsInRound<<endl;
                        cout<<*myGame<<endl;
                        if(numberOfCardsInRound>1){

                            if(rules->isValid(*myGame)==true){
                                cout<<"It is a match!"<<endl;
                                cout<<"--------Player "<<playingNow.getName()<<" finish--------"<<endl;;
                                // nextPlayer++;
                            }
                            else{
                                playingNow.setActive(false);
                                cout<<"It is not a match. "<<playingNow.getName()<<" is out."<<endl;
                                cout<<"--------Player "<<playingNow.getName()<<" finish--------"<<endl;;
                                numberOfActivePlayers--;
                                if(numberOfActivePlayers<2){
                                    Player& winner = myGame->getPlayer(rules->getNextPlayer(*myGame).getSide());
                                    cout<<endl;
                                    cout<<endl;
                                     cout<<"Congratulations! The winner for this round is: "<< winner.getName()<<endl;
                                    winner.addReward(*rDeck->getNext());
                                    cout<<"********Round: "<<myGame->getRound()<<" finish********"<<endl;
                                    myGame->roundFinish();
                                    myGame->nextRound();
                                    cout<<endl;
                                    cout<<endl;
                                    numberOfCardsInRound=0;
                                }
                            }
                        }


                    }
                    if(numberOfFaceUp>23){
                        cout<<"shuffling all cards"<<endl;
                        gameCdeck->roundOverShuffle=true;
                        gameCdeck->make_CardDeck();
                        gameCdeck->roundOverShuffle=false;
                        gameCdeck->make_CardDeck();
                        myGame->gameBoard.reset();
                        cout<<*myGame<<endl;
                        numberOfFaceUp=0;

                    }
                }

            }
            cout<<"##########GAME OVER##########"<<endl;
            cout<<"7 rounds NORMAL mode end"<<endl;
            myGame->getPlayer(Side::top).setDisplayMode(true);
            myGame->getPlayer(Side::bottom).setDisplayMode(true);
            if(myGame->numOfPlayer>2){
                myGame->getPlayer(Side::left).setDisplayMode(true);
                if(myGame->numOfPlayer>3){
                    myGame->getPlayer(Side::right).setDisplayMode(true);
                }
            }
            cout<<*myGame<<endl;
            cout<<"##########GAME OVER##########"<<endl;
        }


}
