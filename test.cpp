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
Game game(One, Two);
CHECK(One.stacksize() == Two.stacksize && One.stacksize==26);
CHECK(One.cardesTaken==0 && Two.cardesTaken==0);
}



TEST_CASE("END THE GAME"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
game.playAll();
CHECK((One.stacksize() == 0 && Two.stacksize==52) ||(One.stacksize() == 52 && Two.stacksize==0));

}


TEST_CASE("Midel the GAME"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
for (int i=0;i<5;i++) {
    game.playTurn();
}

CHECK((One.stacksize() + Two.stacksize ==52));

}


TEST_CASE("OFTER ONE YURN"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
game.playTurn();
CHECK((One.stacksize() >26  && Two.stacksize <26) || (One.stacksize() <26 && Two.stacksize >26));
}

