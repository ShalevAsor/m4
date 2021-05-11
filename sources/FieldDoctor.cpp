#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;


FieldDoctor& FieldDoctor::treat(City name){
    if(this->board.connections.at(this->position).find(name)!=this->board.connections.at(this->position).end()
    &&this->board[name]>0){//the cities are connected and the disease dices is greater then 0
        if(this->board.cures.find(get<Board::COLOR>(this->board.cities.at(name)))!=this->board.cures.end()){//in case that the cure has discovered
            this->board[name]=0;// set to 0
        }
        else{ 
        board[name]--;} // decrease by 1
    }
    else{
        Player::treat(name);
    }
    return *this;
}