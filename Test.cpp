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

    bool con1 =(One.stacksize() == 0);
    bool con2 =(Two.stacksize() == 0);
    bool con3 = One.stacksize() == Two.stacksize();
    bool con1_3 = One.stacksize() == 0 &&  One.stacksize() == Two.stacksize();
    bool con2_3 = Two.stacksize() == 0 &&  One.stacksize() == Two.stacksize();

    CHECK(con2_3);
    CHECK(con1_3);
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
bool con3 = (One.cardesTaken() + Two.cardesTaken()==52);
CHECK(con3);
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
bool con4 = ((One.cardesTaken()>0 || Two.cardesTaken()>0));

CHECK(con4);
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
    CHECK(((One.cardesTaken()>0) || (Two.cardesTaken()>0)));

}
}





TEST_CASE("function are error"){
    

    Player One("One"); //Creating player objects
    Player Two("Two");
    Game game(One, Two);



    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printWiner());

}
