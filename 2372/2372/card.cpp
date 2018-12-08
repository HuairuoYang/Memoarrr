//
//  Card.cpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839)(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839)(7895717) & Yifei Du(7824839)(7895717). All rights reserved.
//

#include "card.hpp"

std::string Card::getAnimalStr(){
    switch (cardAnimal){
        case crab:
            return "C";
        case penguin:
            return "P";
            break;
        case octopus:
            return "O";
            break;
        case turtle:
            return "T";
            break;
        case walrus:
            return "W";
            break;
        default:
            return " ";
            break;
    }
}

std::string Card::getColorStr(){
    switch (cardColor){
        case red:
            return "r";
        case green:
            return "g";
            break;
        case purple:
            return "p";
            break;
        case blue:
            return "b";
            break;
        case yellow:
            return "y";
            break;
        default:
            return " ";
            break;
    }
}
