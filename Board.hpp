#pragma once
#include <iostream>
#include <vector>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_set>
#include <unordered_map>

namespace pandemic{
class Board{

    private:
        const uint DEFAULT_CITY_SIZE=48;
       
        std::unordered_map<std::string,std::unordered_set<std::string>>Connections; 
        std::unordered_set<std::string>Cards;
        std::unordered_map<pandemic::City,uint>Disease_dice;
        std::unordered_map<std::string,pandemic::Color>City_color;
        
         void read();

        
    public:
    Board();
        uint& operator[]( pandemic::City);
        friend std::ostream& operator<<(std::ostream& op,const Board& board);
        bool is_clean();   
        void remove_cures();

        void remove_stations();

        




};
}