
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Test.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"

namespace ariel {

//show me the code for a test that checks that the game is working correctly?
    TEST_CASE("1") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        CHECK_NOTHROW(game.playTurn());
        CHECK_NOTHROW(game.printLastTurn());
        CHECK_NOTHROW(game.playAll());
        CHECK_NOTHROW(game.printWiner());
        CHECK_NOTHROW(game.printLog());
        CHECK_NOTHROW(game.printStats());
    }
    TEST_CASE("2") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        CHECK_THROWS(game.printLastTurn());
        CHECK_THROWS(game.printWiner());
    }
    TEST_CASE("3") {
        Player p1("Alice");
        CHECK_THROWS(Game (p1, p1));
    }
    TEST_CASE("4") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        CHECK_NOTHROW(game.playAll());
        CHECK_THROWS(game.playTurn());
    }
    TEST_CASE("5") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        for (int i=0;i<5;i++) {
            game.playTurn();
        }
        CHECK_NOTHROW(game.printLastTurn());
    }
    TEST_CASE("6") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        for (int i=0;i<7;i++) {
            game.playTurn();
        }
        CHECK_NOTHROW(game.playTurn(););
    }
    TEST_CASE("7") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        for (int i=0;i<5;i++) {
            game.playTurn();
        }
        CHECK(p1.stacksize()<=21);
        CHECK(p2.stacksize()<=21);
    }
    TEST_CASE("8") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        game.playAll();
        CHECK(p1.stacksize()==0);
        CHECK(p2.stacksize()==0);
    }
    TEST_CASE("9") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        CHECK(p1.stacksize()==26);
        CHECK(p2.stacksize()==26);
    }
    TEST_CASE("10") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        CHECK(p1.cardesTaken()==0);
        CHECK(p2.cardesTaken()==0);
    }
    TEST_CASE("11") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        game.playTurn();
        bool size =p1.cardesTaken()>p2.cardesTaken() || p1.cardesTaken()<p2.cardesTaken();
        CHECK(size);
    }
    TEST_CASE("12") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        game.printLastTurn();
        std::cout.rdbuf(old);
        std::string output = buffer.str();
        CHECK(output=="");
    }
    TEST_CASE("13") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        game.printWiner();
        std::cout.rdbuf(old);
        std::string output = buffer.str();
        bool names = output=="Alice" ||output=="Bob"||output=="Draw";
        CHECK_FALSE(names);
        game.playAll();
        std::stringstream buffer1;
        std::streambuf* old1 = std::cout.rdbuf(buffer1.rdbuf());
        game.printWiner();
        std::cout.rdbuf(old1);
        std::string output1 = buffer1.str();
        bool names_ = output1=="Alice"||output1=="Bob"||output1=="Draw";
        CHECK(names_);
    }
    TEST_CASE("14") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        game.printLog();
        std::cout.rdbuf(old);
        std::string output = buffer.str();
        CHECK(output=="");
        std::stringstream buffer1;
        std::streambuf* old1 = std::cout.rdbuf(buffer1.rdbuf());
        game.printStats();
        std::cout.rdbuf(old1);
        std::string output1 = buffer1.str();
        CHECK(output1=="");
    }
    TEST_CASE("15") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        for (int i=0;i<26;i++) {
            game.playTurn();
            if(p1.stacksize()==0 || p2.stacksize()==0) {
                break;
            }
        }
        int total=p1.cardesTaken()+p2.cardesTaken();
        CHECK(total==52);
    }
    TEST_CASE("16") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        Player p3("moshe");
        CHECK_THROWS(Game (p1, p3));
    }
    TEST_CASE("17") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        for (int i=0;i<26;i++) {
            game.playTurn();
            if(p1.stacksize()==0 || p2.stacksize()==0) {
                break;
            }
        }
        int total=p1.cardesTaken()+p2.cardesTaken();
        CHECK(total==52);
        CHECK_THROWS(game.playTurn());
    }
    TEST_CASE("18") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        int total=p1.stacksize()+p2.stacksize();
        CHECK(total==52);
    }
    TEST_CASE("19") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        CHECK(p1.stacksize()==26);
        CHECK(p2.stacksize()==26);
        CHECK(p1.cardesTaken()==0);
        CHECK(p2.cardesTaken()==0);
    }
    TEST_CASE("20") {
        Player p1("Alice");
        Player p2("Bob");
        Game game(p1, p2);
        game.playAll();
        CHECK(p1.stacksize()==0);
        CHECK(p2.stacksize()==0);
    }

} // ariel