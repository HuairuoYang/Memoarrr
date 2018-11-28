//
//  Board.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include "Utils.hpp"
#include "Card.hpp"
#include "Reward.hpp"
#include "CardDeck.hpp"
#include "RewardDeck.hpp"

//Design a class Board which holds an array of strings corresponding to the screen display of the game.
//• bool isFaceUp( const Letter&, const Number&) const returns true if the card at a given position is face up. Letter and Number are enumerations. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
//• bool turnFaceUp( const Letter&, const Number& ) changes the state of the specified card return false if card was up already. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
//• bool turnFaceDown( const Letter&, const Number& ) changes the state of the specified card return false if card was down already. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
//• void reset() changes the state to all cards to be face down.
//A board must be printable with the insertion operator cout << board.

static CardDeck* gameCdeck = &(CardDeck::make_CardDeck());
class Board{
 
public:
    bool isFaceUp( const Letter&, const Number&);
    bool turnFaceUp( const Letter&, const Number&);
    bool turnFaceDown( const Letter&, const Number& );
    void reset();
    friend std::ostream& operator<<(std::ostream& os,Board & b) {
        std::string str;
        if(!gameCdeck->isEmpty()){
        for(int row = 0;row < gameCdeck->getByPosition(0)->getNRows();row++){
            (row==1)?(str+="A"):(str+=" ");
            for(int col = 0; col < 5; col++){
                str+=(*gameCdeck->getByPosition(col))(row);
            }
            str+="\n";
        }
        str+="\n";
        for(int row1 = 0;row1 < gameCdeck->getByPosition(0)->getNRows();row1++){
            (row1==1)?(str+="B"):(str+=" ");
            for(int col1 = 0; col1 < 5; col1++){
                str+=(*gameCdeck->getByPosition(col1+5))(row1);
            }
            str+="\n";
        }
        str+="\n";
        for(int row2 = 0;row2 < gameCdeck->getByPosition(0)->getNRows();row2++){
            (row2==1)?(str+="C"):(str+=" ");
            for(int col2 = 0; col2 < 5; col2++){
                str+=(*gameCdeck->getByPosition(col2+10))(row2);
            }
            str+="\n";
        }
        str+="\n";
        for(int row3 = 0;row3 < gameCdeck->getByPosition(0)->getNRows();row3++){
            (row3==1)?(str+="D"):(str+=" ");
            for(int col3 = 0; col3 < 5; col3++){
                str+=(*gameCdeck->getByPosition(col3+15))(row3);
            }
            str+="\n";
        }
        str+="\n";
        
        for(int row4 = 0;row4 < gameCdeck->getByPosition(0)->getNRows();row4++){
            (row4==1)?(str+="E"):(str+=" ");
            for(int col4 = 0; col4 < 5; col4++){
                str+=(*gameCdeck->getByPosition(col4+20))(row4);
            }
            str+="\n";
        }
        str+="\n";
        str +="   1   2   3   4   5\n";
        }
        else{
            str+="deck empty\n";
        }
        os << str;
        return os;
    }
};

#endif /* Board_hpp */
