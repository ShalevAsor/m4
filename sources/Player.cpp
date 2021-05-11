#include "Player.hpp"

using namespace pandemic;
using namespace std;

/**
 * private method to calculate the number of cards with the give color
 */
int Player::calculate_cards_by_color(const Color color){
    int counter = 0 ; 
    for(const auto& card:this->Cards){
        if(get<Board::COLOR>(this->board.cities.at(card))==color){counter++;}
    }
    return counter;
}

/**
 * discover cure by the give cards amount 
 */
    void Player::discover_cure_by_amount(Color color,int cards_amount){
        if(this->board.cures.find(color)==this->board.cures.end()){// this cure is not discovered yet
        if(!get<Board::RS>(this->board.cities[this->position])){throw out_of_range("no research station in this city");}
     int cards_in_this_color = calculate_cards_by_color(color);// verify the player has enough cards
    int index=0;
    if(cards_in_this_color>=cards_amount){ // if the player has enough cards
        for(const auto& card:this->Cards){ // iterateing the player cards
            if(index<cards_amount){
            if(get<Board::COLOR>(this->board.cities[card])==color){
                this->Cards.erase(card);// remove this card 
                }
            index++;
            }
        }
        this->board.cures.insert(color);   // discover the cure 
    }
    else{throw out_of_range("No enough cards");}
        }
        
    }
/**
 * this method allows the player to drive other city iff they are connected 
 */
Player& Player::drive(City name){
    //if the player current city and the given city are connected
    if(this->board.connections.at(this->position).find(name)==
    this->board.connections.at(this->position).end()){throw std::out_of_range("this city is not connected to the current city");}
    if(this->position==name){throw std::out_of_range("you are already in this city");} // and this is not the same city 
    this->position=name; // allow the player to drive 
    return *this;
}
/**
 * allows the player to fly direct to any city by throwing that city card . 
 */
Player& Player::fly_direct(City name){
    if(this->position==name){throw std::out_of_range("you are already in this city");}// if this is not the same city as the current
    if(this->Cards.find(name)==this->Cards.end()){throw out_of_range("You dont own this city card");}// and the player got that city card
    this->position=name;// allow to fly direct 
    this->Cards.erase(name);// remove the card
    return *this;
}
/**
 * allows to the player to fly charter by throwing the current city card 
 */
Player& Player::fly_charter(City name){
    if(this->position==name){throw std::out_of_range("you are already in this city");}//if this is not the same city as the current
    if(this->Cards.find(this->position)==this->Cards.end()){throw out_of_range("You dont own this city card");}// and the player has the current city card
    this->Cards.erase(this->position);// throw the card
    this->position=name;// change the position of the player 
    return *this;
}
/**
 * allows the player to fly shuttle iff there is a research station in both city
 */
Player& Player::fly_shuttle(City name ){
    if(this->position==name){throw std::out_of_range("you are already in this city");}
    if(!get<Board::RS>(this->board.cities.at(this->position))|| // if there is research station in both cities
    !get<Board::RS>(this->board.cities.at(name))){throw out_of_range("There is no Research station in this city");}
    this->position=name; //change the player position
    return *this;
}
/**
 * build research station the the current city by throwing that city card
 */
Player& Player::build(){
    if(this->Cards.find(this->position)==this->Cards.end()){throw out_of_range("You dont own this city card");}
    get<Board::RS>(this->board.cities.at(this->position))=true;// set the station 
    this->Cards.erase(this->position);// erase the card
    return *this;
}
/**
 * discover the cure with the given color iff the player own the default cards amount 
 */
Player& Player::discover_cure(Color color){
    discover_cure_by_amount(color,DEFAULT_CARDS_AMOUNT);
    return *this;
}
/**
 * decrease the disease dices of the given city by 1 
 * if the cure hase discovered for that city color set the dicese to 0 
 */
Player& Player::treat(City name){
    if(this->position!=name){throw out_of_range("you are not in that city");}
    if(this->board[name]==0){throw out_of_range("disease level already 0 ");}
    if(this->board.cures.find(get<Board::COLOR>(this->board.cities.at(name)))!=this->board.cures.end()){//if this cure is discovered
        this->board[name]= 0 ; // set the level to 0 
        return *this;
    }
    this->board[name]--; 
    return *this;
}
/**
 * return the string represents the player role
 */
string Player::role(){
    return this->_role;
}
/**
 * take card from the board
 */
Player& Player::take_card(City name){
    if(this->Cards.find(name)==this->Cards.end()){this->Cards.insert(name);}// if the player dont own this card already 
    return *this;
}
/**
 * remove all the player cards 
 */
void Player::remove_cards(){
    this->Cards.clear();
    
}
