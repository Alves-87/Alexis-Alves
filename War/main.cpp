#include <iostream>
#include <vector>
#include <algorithm>
#include "deck.hpp"

 int main()
 {  
    //Initlazing game
    // creates a Single deck of cards
    deck a;
    a.suffle();
    std::vector<cards> PlayerOne;
    a.set(PlayerOne, 1 );
    std::vector<cards> PlayerTwo;
    a.set(PlayerTwo, 2 );

   // while(!PlayerOne.empty() || !PlayerTwo.empty())
    // test deck
    /*
    for (int i = 0 ; i < 52 ; ++i)
    {
        std::cout << " cards#" << i << ":   " << a.Read(i).face << std::endl;
        std::cout << " cards#" << i << ":   " << a.Read(i).suits << std::endl;
        std::cout << std::endl;
    }
    */ 
      // test Player Deck
    /*
    for (int i = 0 ; i < 26 ; ++i)
    {
        std::cout << " cards#" << i << ":   " << PlayerOne[i].face << " cards#" << i << ":   " << PlayerTwo[i].face << std::endl;
        std::cout << " cards#" << i << ":   " << PlayerOne[i].suits << " cards#" << i << ":   " << PlayerTwo[i].suits << std::endl;
        std::cout << std::endl;
    }
    */   
 }
