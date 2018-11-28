//
//  Player.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "Player.hpp"

string Player::getSideString(){
    switch (side){
        case PlayerSide::top:
            return "TOP";
        case PlayerSide::bottom:
            return "BOTTOM";
            break;
        case PlayerSide::left:
            return "LEFT";
            break;
        case PlayerSide::right:
            return "RIGHT";
            break;
        default:
            break;
    }
}
