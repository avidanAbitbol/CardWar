#include "player.hpp"
#include <string>

namespace ariel {
    Player::Player() {}
    Player::Player(string name){
         name=name;
    }
    int Player:: stacksize(){
        return 0;
    } //prints the amount of cards left. should be 21 but can be less if a draw was played
    int Player::cardesTaken(){
        return 0;
    }
} // ariel