//
//  Rules.hpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839)(7895717). All rights reserved.
//

#ifndef Rules_hpp
#define Rules_hpp

#include <stdio.h>
#include "game.hpp"
#include "utils.hpp"

class Rules{
public:
    bool isValid(const Game&);
    bool gameOver(const Game&);
    bool roundOver(const Game&);
    const Player& getNextPlayer(const Game&);
};


#endif /* Rules_hpp */
