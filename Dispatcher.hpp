#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

class Dispatcher:public pandemic::Player { 

    private:
        //std::string DEFAULT_RULE_NAME = "OperationsExpert";

    public:
        Dispatcher(pandemic::Board b,pandemic::City pos):pandemic::Player(b,"Dispatcher",pos){}
};