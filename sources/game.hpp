#ifndef CARDWAR_A_GAME_H
#define CARDWAR_A_GAME_H
#include "player.hpp"
namespace ariel {
    class Game {
    public:
        Player p1;
        Player p2;
        Game();
        Game(Player P2,Player P1);

        void playAll(); //playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
        void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
        void printLastTurn(); // print the last turn stats. For example:
        void playTurn();
    };

}; // ariel

#endif //CARDWAR_A_GAME_H
