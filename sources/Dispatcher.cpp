#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;


Dispatcher& Dispatcher::fly_direct(City name){
    
    if(name == this->position){throw out_of_range("already in this city");}
    if(get<Board::RS>(this->board.cities.at(this->position))){ // there is a research station in this city
        //cout<<"visited";
        this->position=name;// change the player position
    }
    else{
        Player::fly_direct(name); // there is no research station so use the basic method
    }
    return *this;
}
