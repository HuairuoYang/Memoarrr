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
        case top:
            return "TOP";
        case bottom:
            return "BOTTOM";
            break;
        case left:
            return "LEFT";
            break;
        case right:
            return "RIGHT";
            break;
        default:
            break;
    }
}
