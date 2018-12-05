//
//  Card.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include "Utils.hpp"
using namespace std;

class Card{
    friend class CardDeck;
    FaceAnimal cardAnimal;
    FaceBackground cardColor;
    Letter let;
    Number num;
    bool faceUp = false;
    int nRows = 3;
    
    Card(FaceAnimal animal, FaceBackground background): cardAnimal(animal), cardColor(background){};
    
public:
    int getPosition() const{
        int pos=0;
        int n=0;
        switch(num){
            case Number::one:
                n=1;
                break;
            case Number::two:
                n=2;
                break;
            case Number::three:
                n=3;
                break;
            case Number::four:
                n=4;
                break;
            case Number::five:
                n=5;
                break;
            dafault: break;
        }
        switch(let){
            case Letter::A:
                pos=n-1;
                cout<<"A"<<endl;
                break;
            case Letter::B:
                pos=n+4;
                cout<<"B"<<endl;
                break;
            case Letter::C:
                pos=n+9;
                cout<<"C"<<endl;
                break;
            case Letter::D:  pos=n+14;
                cout<<"D"<<endl;
                break;
            case Letter::E:  pos=n+19;
                cout<<"E"<<endl;
                break;
            default:
                break;
        }
        return pos;
    }
    void setLetter(Letter l){let=l;}
    void setNumber(Number n){num=n;}
    
    FaceAnimal getAnimal() const {return cardAnimal;}
    std::string getAnimalStr();
    FaceBackground getColor() const {return cardColor;}
    std::string getColorStr();
    
    bool isFaceUp(){return faceUp;}
    void turnFace(bool trueForUp){faceUp = trueForUp;}
    
    Card(const Card&) = delete;
    Card& operator= ( const Card & ) = delete;
    int getNRows() {return nRows;}
    std::string operator()(int i) {
            if(!faceUp){
                return " zzz";
            }
            else{
                if(i==1){
                    return (" "+getColorStr()+getAnimalStr()+getColorStr());
                }
                else{
                    return (" "+(getColorStr()+getColorStr()+getColorStr()));
                }
            }
    }

    
};

#endif /* Card_hpp */
