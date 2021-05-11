#include "Virologist.hpp"
using namespace std;
using namespace pandemic;



Virologist& Virologist::treat(City name){
    if(this->position!=name){// the player is not at this city 
        if(this->Cards.find(name)==this->Cards.end()){throw out_of_range("You dont own this card");}
        City temp = this->position; // save the current city 
        this->position=name; // change the position
        Player::treat(name);// use the basic method
        this->position=temp;// return the position to the original 
        this->Cards.erase(name); // throw the card
    }
    else{// the player in that city - can use the basic method
        Player::treat(name);
    }
    return *this;
}