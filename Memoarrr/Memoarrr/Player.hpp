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


//Design a class Player which combines all information for a player including name, side of the board (top, bottom, left or right) and has the current count of rubies. The class should have the following public methods:
//o stringgetName()constreturnthenameoftheplayer.
//o voidsetActive(bool)setthestatusoftheplayerasactiveorinactive.
//o boolisActive()returnstrueiftheplayerisactive.
//o intgetNRubies()constreturnthenumberofrubieswonbythisplayer.
//o voidaddReward(constReward&)addarewardwithagivennumberofrubies. o voidsetDisplayMode(boolendOfGame)
//A player must be printable with the insertion operator cout << player. An example print out with endOfGame false could look as follows:
//Joe Remember Doe: left (active)
//Once endOfGame is true:
//Joe Remember Doe: 3 rubies

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
    void setActive(){active = true;}
    bool isActive(){return active;}
    int getNRubies(){return countOfRubies;}
    void addReward(const Reward&){};
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
