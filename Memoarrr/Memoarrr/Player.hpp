//
//  Player.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Reward.hpp"
#include "Utils.hpp"

class Player{
    std::string name;
    PlayerSide side;
    int countOfRubies = 0;
    bool active = true;
    Player(){};
public:
    std::string getName(){return name;}
    PlayerSide getSideEnum(){return side;}
    std::string getSideString();
    
   
    bool isActive(){return active;}
    int getNRubies(){return countOfRubies;}
    void addReward(const Reward&){};
    
    void setActive(){active = true;}    
    void setDisplayMode(bool display){active = !display;}
    
    //constructor
    Player(std::string pName, PlayerSide pSide) : name{pName}, side{pSide}{};
    
    friend std::ostream& operator<<(std::ostream& os,Player & p) {
        if(!endOfGame){
            os<<p.name+": " + p.getSideString() + "(" + (p.isActive()? "ACTIVE":"DISPLAY") + ")\n";
        } else {
           os<<p.name + ": " + std::to_string(p.countOfRubies) + " rubies\n";
        }

        return os;
        
    }
};


#endif /* Player_hpp */
