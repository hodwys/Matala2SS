#include "doctest.h"
#include <stdexcept>
#include "iostream"
#include "stdio.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;


TEST_CASE("befor START GAME"){
    

    Player One("One"); //Creating player objects
    Player Two("Two");

    CHECK(One.stacksize() == 0);
    CHECK(Two.stacksize() == 0);
    CHECK(One.cardesTaken() == 0);
    CHECK(Two.cardesTaken() == 0);
}



TEST_CASE("in the START GAME"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
bool con1 = (One.stacksize() == Two.stacksize());
bool con2 = One.stacksize()==26;
bool con1_2 = con1 && con2;

bool con3 = One.cardesTaken()==0;
bool con4 = Two.cardesTaken()==0;


CHECK (con1_2);
CHECK( con3);
CHECK(con4);
}



TEST_CASE("END THE GAME"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
game.playAll();
bool con1 = One.stacksize() == 0;
bool con2 =  Two.stacksize()==0;
CHECK(con1);
CHECK(con2);
CHECK_THROWS(game.playTurn());

}


TEST_CASE("Midel the GAME"){

Player One("One"); 
Player Two("Two");
Game game(One, Two);
for (int i=0;i<5;i++) {
    game.playTurn();
}

bool con1 = (One.stacksize()<20);
bool con2 = (Two.stacksize()<20);
bool con3 = (One.stacksize() == Two.stacksize());

CHECK(con1);
CHECK(con2);
CHECK(con3);
CHECK((One.stacksize() + One.cardesTaken() + Two.stacksize() + Two.cardesTaken() ==52));



}


TEST_CASE("OFTER ONE TURN"){

Player One("One"); //Creating player objects
Player Two("Two");
Game game(One, Two);
game.playTurn();

if(One.stacksize() >0){
    bool con1 = One.cardesTaken() > 0;
    bool con2 = Two.cardesTaken() == 0;
    bool con1_2 = con1 && con2;

    bool con3 = Two.cardesTaken() > 0;
    bool con4 = One.cardesTaken() == 0;
    bool con3_4 = con3 && con4;
    
    CHECK(con1_2);
    CHECK(con3_4);
}

else{
    CHECK(Two.stacksize()==0);

}
}




TEST_CASE("Checking whether after a maximum of 26 turns the game is over"){

    Player One("One"); //Creating player objects
    Player Two("Two");
    Game game(One, Two);

    int count = 0;
    while (1){

        game.playTurn();
        count++;
        if (count ==26  || One.stacksize()==0){
            break;
        }
    }
    bool con1 = One.cardesTaken()>0;
    bool con2 = Two.cardesTaken()>0;

    CHECK(con1);
    CHECK(con2);
    CHECK(One.stacksize() == 0);
    CHECK(Two.stacksize() == 0);
    CHECK(count < 27);
    
}