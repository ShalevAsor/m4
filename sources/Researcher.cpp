#include "Researcher.hpp"
using namespace std;
using namespace pandemic;



Researcher& Researcher::discover_cure(Color color){
    if(!get<Board::RS>(this->board.cities.at(this->position))){
        get<Board::RS>(this->board.cities.at(this->position))=true;//set rs to true
        Player::discover_cure(color);                             //use basic method
        get<Board::RS>(this->board.cities.at(this->position))=false;// set rs to false
    }
    else{Player::discover_cure(color);}
    return *this;
}