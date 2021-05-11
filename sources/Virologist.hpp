#pragma once
#include "Player.hpp"


/**
 * This class represents the Virologist - a type of Player that can treat in any city by throwing that city card  
 */

class Virologist:public pandemic::Player { 

    public:
        Virologist& treat(pandemic::City name);
        Virologist(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"Virologist",pos){}
};