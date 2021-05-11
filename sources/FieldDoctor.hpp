#pragma once
#include "Player.hpp"


/**
 * This class represents the FieldDoctor - a type of Player that can treat in connected cities without being in that city  
 * and throwing a card
 */

class FieldDoctor:public pandemic::Player { 


    public:
        FieldDoctor& treat(pandemic::City name);
        FieldDoctor(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"FieldDoctor",pos){}
};