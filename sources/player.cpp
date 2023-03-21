# include "player.hpp"
# include <string>

Player::Player(std::string s){
    nameP=s;
}// constructor 

std::string Player::getString(){
    return nameP;
}

int Player::stacksize(){
    return 1;

}  //prints the amount of cards left. should be 21 but can be less if a draw was played


int Player::cardesTaken(){
    return 1;

}// prints the amount of cards this player has won. 

