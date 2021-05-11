#pragma once
#include "Player.hpp"


/**
 * This class represents the GeneSplicer - a type of Player that can discover cure with any type of cards 
 */

class GeneSplicer:public pandemic::Player { 

    public:
        GeneSplicer& discover_cure(pandemic::Color color);
        GeneSplicer(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"GeneSplicer",pos){}
};