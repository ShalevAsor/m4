#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

class Scientist:public pandemic::Player { 

    private:
        uint _cards;
        //std::string DEFAULT_RULE_NAME = "OperationsExpert";

    public:
        Scientist(pandemic::Board b,pandemic::City pos):pandemic::Player(b,"Scientist",pos){}
        Scientist(pandemic::Board b,pandemic::City pos,uint cards):pandemic::Player(b,"Scientist",pos),_cards(cards){}
};