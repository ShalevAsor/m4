#pragma once
#include "City.hpp"
#include <unordered_set>
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic{
class Player{
    protected:
        pandemic::City position;
        std::unordered_set<std::string> Cards;
        std::string _rule;
        Board board;
    public:
        Player& drive(const pandemic::City name);

        virtual Player& fly_direct(const pandemic::City name);

        Player& fly_charter(const pandemic::City name);

        Player& fly_shuttle(const pandemic::City name);

        virtual void build();

        virtual void discover_cure(Color);

        virtual Player& treat(const pandemic::City name);

        virtual std::string role();

        Player& take_card(const pandemic::City name);

        void remove_cards();

        Player(Board b,std::string rule,pandemic::City city):_rule(rule),board(b),position(city){}

        Player(Board b,std::string rule,pandemic::City city,uint cards):_rule(rule),board(b),position(city){
            
        }







};
}