#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

GeneSplicer& GeneSplicer::discover_cure(Color color){
    if(this->board.cures.find(color)==this->board.cures.end()){//the cure isnt discovered yet
    if(!get<Board::RS>(this->board.cities.at(this->position))){throw out_of_range("No research station in this city");}
    if(this->Cards.size()<DEFAULT_CARDS_AMOUNT){throw out_of_range("You dont have enough cards to discover cure");}
        int i = 0 ; 
    while(i<DEFAULT_CARDS_AMOUNT){
            this->Cards.erase(*this->Cards.begin()); // remove the card 
            ++i;
    }
    this->board.cures.insert(color); // add that color to the discovered set
    }
    return *this;
}