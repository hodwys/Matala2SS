#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>
#include <stdexept>

using namespace std;
#include "iostream"
#include "stdio.h"


class Player{
    
    private:
        std::string nameP;
    
    public:
        Player(){}
        Player(std::string s);

        std::string getString();

        int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played

        int cardesTaken();

};

#endif



