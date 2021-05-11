#pragma once
#include <unordered_set>
#include "Board.hpp"

/**
 * This class represents a general Player in the pandemic game 
 */
namespace pandemic{
class Player{
    private :
        int calculate_cards_by_color(const Color color);
        
    protected:
        int DEFAULT_CARDS_AMOUNT=5;
        City position;

        std::unordered_set<City> Cards;
        std::string _role;
        Board& board;
        void discover_cure_by_amount(Color color,int cards_amount);
    public:
        virtual Player& drive(const pandemic::City name);

        virtual Player& fly_direct(pandemic::City name);

        virtual Player& fly_charter(pandemic::City name);

        virtual Player& fly_shuttle(pandemic::City name);

        virtual Player& build();

        virtual Player& discover_cure(Color color);

        virtual Player& treat(pandemic::City name);

        virtual std::string role();

        Player& take_card(pandemic::City name);

        void remove_cards();

        Player(Board& b,std::string role,pandemic::City city):_role(role),board(b),position(city){}

        Player(Board& b,pandemic::City city):board(b),position(city){}

        Player(Board& b,std::string role,pandemic::City city,int cards):board(b),_role(role),position(city){}
};
}