//
//  main.cpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#include <iostream>

//game rules:

//25 memory cards that will show a combination of an animal and a background colour
// five different animals: crab, penguin, octopus, turtle and walrus
// five different background colours: red, green, purple, blue and yellow

//2-4 players

/*
 cards are placed face down in a 5 times 5 square
 but the center position remains free for the volcano and treasure cards.
 (Note that means one of the regular animal card is not in the game).
 In our adaption, we don’t use volcano or treasure cards but simply leave the center position empty.
 */

 /*
 The players take turns to uncover a card where the uncovered card has to match
  the previously uncovered card’s animal or background colour.
 The uncovered cards remain on the table face up.
 If the player uncovers a card that doesn’t match the previously uncovered card,
 the player is out of the current round.
  */

/*
 A round of play ends with only one player remaining who then wins the current round
 and receives 1-4 rubies randomly.
 If there are no more cards to turn over then the players still in the game continue to take their turns
 but lose until only one player is left who wins the round.
 After the current round the cards remain in place but are turned face down again.
 */

/*
 After seven rounds, the game ends and the player with the most rubies wins.
 In the physical game there are 3 cards with one ruby, 2 cards with 2 rubies,
 and 1 card with 3 rubies as well as 1 with 4 rubies.
 */

/*
 psudo code:
 
 Ask player to choose game version, number of players and names of players.
Create the corresponding players, rules, cards and board for the game. Display game (will show board and all players)
while Rules.gameOver is false{
    update status of cards in board as face down
    update status of all players in game as active
    for each player{
        Temporarily reveal 3 cards directly in front of the player
    }
     while Rules.roundOver is false{
        # next active player takes a turn
        get selection of card to turn face up from active player
        update board in game
        if Rules.isValid(card) is false{
             # player is no longer part of the current round
             current player becomes inactive
     }
     display game
     }
     Remaining active player receives reward (rubies)
 }
 print players with their number of rubies sorted from least to most rubies
 print overall winner
 */



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
