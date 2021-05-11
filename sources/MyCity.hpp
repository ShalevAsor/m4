#pragma once 
#include <iostream>
#include <array>
#include "Color.hpp"
#include <unordered_set>
#include "City.hpp"


namespace pandemic{ 

class MyCity{
    private : 

    public : 
        std::unordered_set<std::string> connections; 
        int disease_dice=0; 
        Color _color; 
        bool station; 
        City city;

        MyCity(pandemic::Color color,pandemic::City c=City::Algiers):_color(color),city(c){}

         void  add_connection(std::string city){
            connections.insert(city);
            
        }
        void set_station(bool condition){
            this->station=condition;
        }
        MyCity(){}

        std::string to_string(){
            std::string c;
            c= "[Color:" + std::to_string(_color) + "]";
            std::string d = "[Dices:" + std::to_string(disease_dice) +"]";
            std::string con="[connections:";
            for(const auto& city:connections){
                con+=city+",";
                
            }
            con+= "]";
            return c+d+con;
        }

};


}