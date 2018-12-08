//
//  Player.cpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839)(7895717). All rights reserved.
//

#include "player.hpp"

std::string Player::getSideString() const{
    switch (side){
        case Side::top:
            return "TOP";
            break;
        case Side::bottom:
            return "BOTTOM";
            break;
        case Side::left:
            return "LEFT";
            break;
        case Side::right:
            return "RIGHT";
            break;
        default:
            break;
    }
}
