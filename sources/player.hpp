#ifndef CARDWAR_A_PLAYER_H
#define CARDWAR_A_PLAYER_H
#include <string>
using namespace std;
namespace ariel {

    class Player {
    public:
        Player();
        Player(string);
        int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played
        int cardesTaken(); // prints the amount of cards this player has won.
        string name;

    };

} // ariel

#endif //CARDWAR_A_PLAYER_H
