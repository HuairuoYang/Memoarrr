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
#include "Utils.hpp"

class Rules{
    int currentPlayer;
public:
    bool isValid(const Game&);
    bool gameOver(const Game&);
    bool roundOver(const Game&);
    Player& getNextPlayer(const Game&);
};


#endif /* Rules_hpp */
