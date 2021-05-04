#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

class GeneSplicer:public pandemic::Player { 

    private:
        //std::string DEFAULT_RULE_NAME = "OperationsExpert";

    public:
        GeneSplicer(pandemic::Board b,pandemic::City pos):pandemic::Player(b,"GeneSplicer",pos){}
};