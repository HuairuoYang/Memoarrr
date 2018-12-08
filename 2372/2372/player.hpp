//
//  Player.hpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839)(7895717). All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "reward.hpp"
#include "utils.hpp"

class Player{
    std::string name;
    Side side;
    int countOfRubies = 0;
    bool active = true;
    bool display = false;
public:
    std::string getName() const {return name;}
    Side getSide() const {return side;}
    std::string getSideString() const;
    void setSide(Side s) { side = s;}
    
    bool isActive() const {return active;}
    int getNRubies() const {return countOfRubies;}
    void addReward(Reward& r) {
        std::cout<<name<<": you have been rewarded "<<r.getRubies()<<" rubies"<<std::endl;
        countOfRubies=countOfRubies+ r.getRubies();
    };
    
    void setActive(bool trueIfActive)  {active = trueIfActive;}
    void setDisplayMode(bool dspl)  {display = dspl;}
    
    //constructor
    Player()= default;
    Player(std::string pName, Side pSide) : name{pName}, side{pSide}{};
    
    friend std::ostream& operator<<(std::ostream& os,Player & p) {
        if(!p.display){
            os<<p.name+": " + p.getSideString() + " (" + (p.isActive()? "ACTIVE":"INACTIVE") + ")";
        } else {
           os<<p.name + ": " + std::to_string(p.countOfRubies) + " rubies";
        }

        return os;
        
    }
};


#endif /* Player_hpp */
