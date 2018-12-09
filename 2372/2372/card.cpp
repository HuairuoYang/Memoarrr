//
//  Card.cpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
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

std::string Card::getPositionString(){
    std::string rtn = "";
    switch (let){
        case (Letter::A):
            rtn+= "A";
            break;
        case (Letter::B):
            rtn+=  "B";
            break;
        case (Letter::C):
            rtn+=  "C";
            break;
        case (Letter::D):
            rtn+=  "D";
            break;
        case (Letter::E):
            rtn+=  "E";
            break;
        default:
            rtn+=  " ";
            break;
    }
    switch (num){
        case (Number::one):
            rtn+= "1";
            break;
        case (Number::two):
            rtn+=  "2";
            break;
        case (Number::three):
            rtn+=  "3";
            break;
        case (Number::four):
            rtn+=  "4";
            break;
        case (Number::five):
            rtn+=  "5";
            break;
        default:
            rtn+=  " ";
            break;
    }
    return rtn;
}
void Card::turnFace(bool trueForUp){
    faceUp = trueForUp;
    if(faceUp){
        cardsFaceup.push_back((int)let*5 + (int)num);
    }
    else{
        cardsFaceup.erase(find (cardsFaceup.begin(), cardsFaceup.end(), (int)let*5 + (int)num));
    }
}
