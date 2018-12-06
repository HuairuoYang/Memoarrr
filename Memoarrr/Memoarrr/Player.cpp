//
//  Player.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include "Player.hpp"

std::string Player::getSideString() const{
    switch (side){
        case Side::top:
            return "TOP";
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
