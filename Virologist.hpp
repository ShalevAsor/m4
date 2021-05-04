#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

class Virologist:public pandemic::Player { 

    private:
        //std::string DEFAULT_RULE_NAME = "OperationsExpert";

    public:
        Virologist(pandemic::Board b,pandemic::City pos):pandemic::Player(b,"Virologist",pos){}
};