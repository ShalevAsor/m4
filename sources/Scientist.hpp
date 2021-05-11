#pragma once
#include "Player.hpp"


/**
 * This class represents the Scientist - a type of Player that can discover cure with n cards (given in the constructor )
 */


class Scientist:public pandemic::Player { 


    public:
        Scientist& discover_cure(pandemic::Color color);
        Scientist(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"Scientist",pos){} // n = default
        Scientist(pandemic::Board& b,pandemic::City pos,int cards):pandemic::Player(b,"Scientist",pos){// n = cards
            this->DEFAULT_CARDS_AMOUNT=cards;
        }
};