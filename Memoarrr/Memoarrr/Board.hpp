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
#include "Utils.hpp"

//Design a class Board which holds an array of strings corresponding to the screen display of the game.
//• bool isFaceUp( const Letter&, const Number&) const returns true if the card at a given position is face up. Letter and Number are enumerations. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
//• bool turnFaceUp( const Letter&, const Number& ) changes the state of the specified card return false if card was up already. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
//• bool turnFaceDown( const Letter&, const Number& ) changes the state of the specified card return false if card was down already. Throws an exception of type OutOfRange if an invalid Letter and Number combination was given.
//• void reset() changes the state to all cards to be face down.
//A board must be printable with the insertion operator cout << board.

class Board{
    bool isFaceUp( const Letter&, const Number&);
    bool turnFaceUp( const Letter&, const Number&);
    bool turnFaceDown( const Letter&, const Number& );
    void reset();
};

#endif /* Board_hpp */
