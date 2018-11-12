//
//  Rules.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Rules_hpp
#define Rules_hpp

#include <stdio.h>
#include "Game.hpp"
//Design a class Rules which has the main purpose to check if a selection of a player is valid.
//• bool isValid(const Game&) returns true is previous and current card match; false otherwise.
//• bool gameOver(const Game&) returns true if the number of rounds has reached 7.
//• bool roundOver(const Game&) returns true if there is only one active Player left.
//The remaining marks are for the expert modes. Expert Display [2] and Expert Rules [4].

class Rules{
    bool isValid(const Game&);
    bool gameOver(const Game&);
    bool roundOver(const Game&);
};

#endif /* Rules_hpp */
