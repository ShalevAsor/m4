#include "Player.hpp"
#include "Board.hpp"

using namespace pandemic;
using namespace std;

Player& Player::drive(const City name){
    return *this;
}
Player& Player::fly_direct(const City name){
    return *this;
}
Player& Player::fly_charter(const City name){
    return *this;
}
Player& Player::fly_shuttle(const City name ){
    return *this;
}
void Player::build(){

}
void Player::discover_cure(Color color){

}

Player& Player::treat(const City name){
    return *this;
}
string Player::role(){
    return " ";

}

Player& Player::take_card(const City name ){
    return *this;
}

void Player::remove_cards(){
    
}
