#pragma once
#include "Player.hpp"

/**
 * This class represents the OperationsExpert- a type of Player that can build without throwing a card 
 */

class OperationsExpert:public pandemic::Player { 


    public:
        
        OperationsExpert& build()override;
        OperationsExpert(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"OperationsExpert",pos){}
};