//
//  CardDeck.hpp
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
//

#ifndef CardDeck_hpp
#define CardDeck_hpp

#include <stdio.h>
#include <iostream>
#include "deck.hpp"
#include "card.hpp"

class CardDeck : public Deck<Card> {
    static CardDeck* myCDeck;
    CardDeck() = default;
    CardDeck(const CardDeck&) = delete;
    CardDeck& operator= ( const CardDeck & ) = delete;
public:
    static bool roundOverShuffle;
    
    static CardDeck& make_CardDeck();
};

#endif /* CardDeck_hpp */
