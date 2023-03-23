#include "doctest.h"
#include <stdexcept>
#include "iostream"
#include "stdio.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;



TEST_CASE("BEFOR START GAME"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
bool con1 = (One.stacksize() == Two.stacksize());
bool con2 = One.stacksize()==26;
bool con1_2 = con1 && con2;

bool con3 = One.cardesTaken()==0;
bool con4 = Two.cardesTaken()==0;
bool con3_4 = con3 && con4;

CHECK (con1_2);
CHECK( con3_4);
}



TEST_CASE("END THE GAME"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
game.playAll();
bool con1 = One.stacksize() == 0;
bool con2 =  Two.stacksize()==0;
bool con1_2 = con1 && con2;
CHECK(con1_2);


}


TEST_CASE("Midel the GAME"){

Player One("One"); 
Player Two("Two");
Game game(One, Two);
for (int i=0;i<5;i++) {
    game.playTurn();
}
CHECK((One.stacksize() + One.cardesTaken() + Two.stacksize() + Two.cardesTaken() ==52));

}


TEST_CASE("OFTER ONE TURN"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
game.playTurn();
bool con1 = One.cardesTaken() > 0;
bool con2 = Two.cardesTaken() == 0;
bool con1_2 = con1 && con2;
bool con3 = Two.cardesTaken() > 0;
bool con4 = One.cardesTaken() == 0;
bool con3_4 = con3 && con4;
bool con1_4 = con1_2 || con3_4;
CHECK(con1_4);
}




