#pragma once
#include "Player.hpp"

/**
 * This class represents the Researcher - a type of Player that can discover cure without a research station
 */

class Researcher:public pandemic::Player { 

    public:
        Researcher& discover_cure(pandemic::Color color);
        Researcher(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"Researcher",pos){}
};