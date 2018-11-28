//
//  Card.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>
#include "Utils.hpp"
//Design a class Card which can take a face of one of the five possible animals and one of the five background colours. A card must also be “printable” as one string per row with the method:
//Card c(Penguin,Red); // This constructor will be private
//for (int row = 0; row <c.getNRows(); ++row ) {
//    std::string rowString = c(row);
//    std::cout << rowString << std::endl;
//    }
//    Note that Penguin and Red are enumeration values of type FaceAnimal and FaceBackground.
//    An object of type Card can not be copied or assigned and needs a private constructor but will give CardDeck (see below) friend access.

// five different animals: crab, penguin, octopus, turtle and walrus
// five different background colours: red, green, purple, blue and yellow

//enum FaceAnimal{
//    crab = 0,
//    penguin,
//    octopus,
//    turtle,
//    walrus
//};
//
//enum FaceBackground {
//    red = 0,
//    green,
//    purple,
//    blue,
//    yellow
//};

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

    int getPosition() const {return let*5+num;}
    void setLetter(Letter l){let=l;}
    void setNumber(Number n){num=n;}
    
    FaceAnimal getAnimal(){return cardAnimal;}
    std::string getAnimalStr();
    FaceBackground getColor(){return cardColor;}
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
