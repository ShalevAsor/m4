#include "Medic.hpp"
using namespace std;
using namespace pandemic;

bool Medic::cure_discovered(Color color){
    return this->board.cures.find(color)!=this->board.cures.end(); // return true if the cure has discovered
}

Medic& Medic::treat(City name){
    if(this->board[name]==0){throw out_of_range("disease level is already 0 ");}
        this->board[name]=0;
        return *this;
}
Medic& Medic::drive(City name){
    Player::drive(name);
    if(cure_discovered(get<Board::COLOR>(this->board.cities.at(name)))){
        this->board[name]=0;
    }
    return *this;
}
Medic& Medic::fly_direct(pandemic::City name){
    Player::fly_direct(name);
    if(cure_discovered(get<Board::COLOR>(this->board.cities.at(name)))){
        this->board[name]=0;
    }
    return *this;
}
        Medic& Medic::fly_charter(pandemic::City name){
            Player::fly_charter(name);
            if(cure_discovered(get<Board::COLOR>(this->board.cities.at(name)))){
        this->board[name]=0;
        }
        return *this;
    }
        Medic& Medic::fly_shuttle(pandemic::City name){
            Player::fly_shuttle(name);
            if(cure_discovered(get<Board::COLOR>(this->board.cities.at(name)))){
        this->board[name]=0;
        }
        return *this;
    }