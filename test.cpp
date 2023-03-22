#include "doctest.h"
#include <stdexept>
#include "iostream"
#include "stdio.h"
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace std;



TEST_CASE("BEFOR START GAME"){

Player One("One"); //Creating player objects
Player Two("Two");
Game(One, Two);
CHECK(One.stacksize() == Two.stacksize && One.stacksize==26);
}



