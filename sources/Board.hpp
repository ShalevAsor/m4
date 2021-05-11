#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_set>
#include <unordered_map>
#include "MyCity.hpp"
#include <fstream>
#include <tuple>
#include <set>


/**
 * This class represents a board in the pandemic game 
 *  each method attached with explanations in the implemantion including the privte methods. 
 */

namespace pandemic{

    class Board
    {

    private:
        static const int DEFAULT_CITIES_SIZE = 48;
        void init_cities(std::ifstream &file);
        void init_connections(std::ifstream &file);
        static pandemic::City str_to_city(const std::string &city);
        static std::string city_to_str(const pandemic::City& city);
        static Color str_to_color(const std::string &color);
        std::string build_city_cube(pandemic::City city)const;
        static std::string color_to_str(const pandemic::Color color);

        void read();

    public:
        static const int DICES = 2;
        static const int RS = 1;
        static const int COLOR = 0;
        int get_cities_size()
        {
            return DEFAULT_CITIES_SIZE;
        }
        std::unordered_set<Color> cures;
        std::set<pandemic::City> Cards;
        std::unordered_map<pandemic::City, std::tuple<Color, bool, int>> cities;
        std::unordered_map<pandemic::City, std::unordered_set<pandemic::City>> connections;

        Board();
        int &operator[](pandemic::City);
        friend std::ostream &operator<<(std::ostream &op, const Board &board);
        bool is_clean();
        void remove_cures();
        void remove_stations();
    };
}