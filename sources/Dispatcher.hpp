#pragma once
#include "Player.hpp"
/**
 * This class represents the Dispatcher - a type of Player that can fly direct without throwing any card 
 * iff there is a research station in the current city 
 */
class Dispatcher:public pandemic::Player { 

    public:
        Dispatcher& fly_direct(pandemic::City name);
        Dispatcher(pandemic::Board& b,pandemic::City pos):pandemic::Player(b,"Dispatcher",pos){}
};