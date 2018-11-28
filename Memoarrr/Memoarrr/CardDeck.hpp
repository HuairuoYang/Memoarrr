//
//  CardDeck.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef CardDeck_hpp
#define CardDeck_hpp

#include <stdio.h>
#include <iostream>
#include "Deck.hpp"
#include "Card.hpp"
//Design a class CardDeck derived from Deck<Card>.
//• static CardDeck& make_CardDeck() is the only public method for CardDeck. The method has to always return the same CardDeck during the execution of the program.
//An object of type CardDeck can not be copied or assigned, and it has no public constructor.

class CardDeck : public Deck<Card> {
    static CardDeck* myCDeck;
    CardDeck() = default;
    CardDeck(const CardDeck&) = delete;
    CardDeck& operator= ( const CardDeck & ) = delete;
public:
    static CardDeck& make_CardDeck();
};

#endif /* CardDeck_hpp */
