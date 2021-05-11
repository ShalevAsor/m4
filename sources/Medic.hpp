#pragma once
#include "Player.hpp"

/**
 * This class represents the Medic- a type of Player that can treat the disease level to 0 , 
 * if the cure has discovered each city that the Medic is visiting automatically decreaseing the disease level to 0 
 */

class Medic:public pandemic::Player { 

    private:
    bool cure_discovered(pandemic::Color color);
        

    public:
        Medic& drive(pandemic::City name);
        Medic& fly_direct(pandemic::City name);
        Medic& fly_charter(pandemic::City name);
        Medic& fly_shuttle(pandemic::City name);
        Medic& treat(pandemic::City name);
        Medic(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"Medic",pos){}
};