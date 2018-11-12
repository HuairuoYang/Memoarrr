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

class Card{
    FaceAnimal cardAnimal;
    FaceAnimal cardColor;
};

#endif /* Card_hpp */
