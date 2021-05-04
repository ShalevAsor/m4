#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

class OperationsExpert:public pandemic::Player { 

    private:
        //std::string DEFAULT_RULE_NAME = "OperationsExpert";

    public:
        OperationsExpert(pandemic::Board b,pandemic::City pos):pandemic::Player(b,"OperationsExpert",pos){}
};