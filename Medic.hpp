#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

class Medic:public pandemic::Player { 

    private:
        //std::string DEFAULT_RULE_NAME = "OperationsExpert";

    public:
        Medic(pandemic::Board b,pandemic::City pos):pandemic::Player(b,"Medic",pos){}
};