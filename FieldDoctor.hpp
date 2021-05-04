#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

class FieldDoctor:public pandemic::Player { 

    private:
        //std::string DEFAULT_RULE_NAME = "OperationsExpert";

    public:
        FieldDoctor(pandemic::Board b,pandemic::City pos):pandemic::Player(b,"FieldDoctor",pos){}
};