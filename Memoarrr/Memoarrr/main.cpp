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

using namespace std;

static bool expertMode;

int main(int argc, const char * argv[]) {
    
    cout << "Hello, World!\n"<<endl;
    Game* myGame = new Game();
    cout<<*myGame<<endl;
    
    myGame->gameBoard.turnFaceUp(Letter::A, Number::one);
    myGame->gameBoard.turnFaceUp(Letter::B, Number::two);
    myGame->gameBoard.turnFaceUp(Letter::C, Number::three);
    myGame->gameBoard.turnFaceUp(Letter::D, Number::four);
    myGame->gameBoard.turnFaceUp(Letter::E, Number::five);
    
    Player* A = new Player("AA",(PlayerSide::top));
    Player* B = new Player("BB",(PlayerSide::bottom));
    Player* C = new Player("CC",(PlayerSide::left));
    Player* D = new Player("DD",(PlayerSide::right));
    myGame->addPlayer(*A);

    myGame->addPlayer(*B);
    
    myGame->addPlayer(*C);
    myGame->addPlayer(*D);
    cout<<*myGame<<endl;
    
    myGame->gameBoard.reset();
      cout<<*myGame<<endl;
    for (int i =0;i<5;i++){
        for(int j =0;j<5;j++){
            myGame->gameBoard.turnFaceUp((Letter)i, (Number)j);
        }
    }
    endOfGame = true;
    cout<<*myGame<<endl;
    return 0;
}
